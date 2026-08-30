#include "Common/Definition.h"
#include "Mcal/GIE/GIE_Interface.h"
#include "Mcal/DIO/DIO_Interface.h"
#include "Mcal/Timer0/T0_Interface.h"
#include "Mcal/Timer1/T1_Interface.h"
#include "Hal/Segment/Segment_Interface.h"
#include "Hal/Button/Button_Interface.h"
#include "Hal/Buzzer/Buzzer_Interface.h"

/* -------------------- pin mapping (edit to match your board) ------------ */
/* LED brightness uses hardware PWM on OC1A, which on the ATmega32 is
 * fixed to Port D, Pin 5 -- this cannot be moved to another pin.
 */
#define LED_PWM_GROUP    DIO_GroupD
#define LED_PWM_PIN      DIO_Pin5

#define BUZZER_GROUP     DIO_GroupA
#define BUZZER_PIN       DIO_Pin1

#define SSD_GROUP        DIO_GroupB
#define SSD_TYPE         SSD_Cathode

#define BUTTON1_GROUP    DIO_GroupC   /* increase brightness */
#define BUTTON1_PIN      DIO_Pin0
#define BUTTON2_GROUP    DIO_GroupC   /* decrease brightness */
#define BUTTON2_PIN      DIO_Pin1
#define BTN_CONNECTION   Button_InternalPullUp

/* -------------------- brightness step / limits --------------------------- */
#define BRIGHTNESS_STEP  (17U) /* ~15 steps to go from 0 to 255 */
#define BRIGHTNESS_MIN   (0U)
#define BRIGHTNESS_MAX   (255U)

/* -------------------- 1 ms base tick (F_CPU=8MHz, Prescaler=64) --------- */
#define T0_OCR_1MS       ((uint8_t)(125U - 1U))    /* CTC mode: OCR0 value */

/* All variables touched inside the Timer0 ISR callback are volatile,
 * since Timer0_1ms_Tick() runs in interrupt context.
 */
static volatile uint16_t Ms_Ticks        = 0U;
static volatile uint8_t  Segment_Digit   = 0U;
static volatile uint8_t  Led_Brightness  = 128U; /* brightness level while LED is "on", set by buttons */
static volatile uint8_t  Led_BlinkIsOn   = 1U;    /* which half of the 500ms blink we're in */
static volatile uint8_t  Buzzer_IsOn     = 0U;    /* software-tracked state, since Buzzer_Toggle doesn't exist */
static volatile uint8_t  Button1_Prev    = PullUp_NotPressed;
static volatile uint8_t  Button2_Prev    = PullUp_NotPressed;

static void Timer0_1ms_Tick(void)
{
    Ms_Ticks++;

    /* Task 1: LED toggle every 500 msec. "On" applies the current
     * brightness to the PWM channel, "off" drops it to 0.
     */
    if((Ms_Ticks % 500U) == 0U)
    {
        Led_BlinkIsOn = (Led_BlinkIsOn == 1U) ? 0U : 1U;
        T1_SetCompareValue(T1_Channel_A, (Led_BlinkIsOn == 1U) ? Led_Brightness : 0U);
    }

    /* Task 2: Buzzer toggle every 150 msec (Buzzer HAL has On/Off only,
     * so the on/off state is tracked here and applied explicitly).
     */
    if((Ms_Ticks % 150U) == 0U)
    {
        Buzzer_IsOn = (Buzzer_IsOn == 1U) ? 0U : 1U;
        if(Buzzer_IsOn == 1U)
        {
            Buzzer_On(BUZZER_GROUP, BUZZER_PIN);
        }
        else
        {
            Buzzer_Off(BUZZER_GROUP, BUZZER_PIN);
        }
    }

    /* Task 3: 7-segment count-up every 1 sec */
    if((Ms_Ticks % 1000U) == 0U)
    {
        Segment_Digit = (uint8_t)((Segment_Digit + 1U) % 10U);
        SSD_DisplayNumber(SSD_GROUP, SSD_TYPE, Segment_Digit);
    }

    /* Task 4 & 5: check both buttons every 200 msec */
    if((Ms_Ticks % 200U) == 0U)
    {
        uint8_t Button1_Now = Btn_ReadState(BUTTON1_GROUP, BUTTON1_PIN, BTN_CONNECTION);
        uint8_t Button2_Now = Btn_ReadState(BUTTON2_GROUP, BUTTON2_PIN, BTN_CONNECTION);

        /* Edge detection: act only on the moment of a fresh press,
         * not on every 200 msec scan while the button stays held.
         */
        if((Button1_Now == PullUp_Pressed) && (Button1_Prev == PullUp_NotPressed))
        {
            if(Led_Brightness <= (uint8_t)(BRIGHTNESS_MAX - BRIGHTNESS_STEP))
            {
                Led_Brightness = (uint8_t)(Led_Brightness + BRIGHTNESS_STEP);
            }
            else
            {
                Led_Brightness = BRIGHTNESS_MAX;
            }

            if(Led_BlinkIsOn == 1U)
            {
                T1_SetCompareValue(T1_Channel_A, Led_Brightness); /* apply immediately if LED is currently on */
            }
        }

        if((Button2_Now == PullUp_Pressed) && (Button2_Prev == PullUp_NotPressed))
        {
            if(Led_Brightness >= BRIGHTNESS_STEP)
            {
                Led_Brightness = (uint8_t)(Led_Brightness - BRIGHTNESS_STEP);
            }
            else
            {
                Led_Brightness = BRIGHTNESS_MIN;
            }

            if(Led_BlinkIsOn == 1U)
            {
                T1_SetCompareValue(T1_Channel_A, Led_Brightness);
            }
        }

        Button1_Prev = Button1_Now;
        Button2_Prev = Button2_Now;
    }

    if(Ms_Ticks >= 3000U) /* LCM(500,150,1000,200) = 3000 -> keep counter small */
    {
        Ms_Ticks = 0U;
    }
}

int main(void)
{
    /* ---- HAL init ---- */
    Buzzer_Init(BUZZER_GROUP, BUZZER_PIN);

    SSD_Init(SSD_GROUP);
    SSD_DisplayNumber(SSD_GROUP, SSD_TYPE, Segment_Digit);

    Btn_Init(BUTTON1_GROUP, BUTTON1_PIN, BTN_CONNECTION);
    Btn_Init(BUTTON2_GROUP, BUTTON2_PIN, BTN_CONNECTION);

    /* ---- Timer0: 1ms base tick, CTC mode -- drives all 5 tasks above ---- */
    T0_Config_t Timer0_Cfg =
    {
        .Prescaler     = T0_Prescaler64,
        .Mode          = T0_CTC,
        .OC0Mode       = T0_OC0_Disconnected,
        .OVFInterrupt  = T0_InterruptDisable,
        .CompInterrupt = T0_InterruptEnable,
        .CompareValue  = T0_OCR_1MS
    };
    T0_Init(&Timer0_Cfg);
    T0_SetCompareCallBack(Timer0_1ms_Tick);

    /* ---- Timer1: Fast PWM 8-bit on OC1A for LED brightness ----
     * T1_Init() only configures WGM/prescaler/registers -- it does NOT
     * set the OC1A pin (PD5) direction, so that must be done manually.
     */
    DIO_DirectionSelectforPin(LED_PWM_GROUP, LED_PWM_PIN, DIO_Outputfor1Pin);

    T1_Init(T1_FastPWM_8bit, T1_Prescaler_8);
    T1_SetCompareOutputMode(T1_Channel_A, T1_OC_NonInverting);
    T1_SetCompareValue(T1_Channel_A, Led_Brightness); /* start already lit at the default brightness */

    GIE_Enable();

    while(1)
    {
        /* Everything is driven from the Timer0 ISR callback above. */
    }
}
