#ifndef T2_PRIVATE
#define T2_PRIVATE

/* TCCR2 bits */
#define Bit_CS20     0
#define Bit_CS21     1
#define Bit_CS22     2
#define Bit_WGM21    3
#define Bit_COM20    4
#define Bit_COM21    5
#define Bit_WGM20    6
#define Bit_FOC2     7

/* TIMSK bits */
#define Bit_TOIE2    6
#define Bit_OCIE2    7

/* TIFR bits */
#define Bit_TOV2     6
#define Bit_OCF2     7

/* SFIOR bits */
#define Bit_PSR2     1
#define Bit_AS2      3

#define T2_CS_MASK        0xF8   /* clears CS22:CS21:CS20 */
#define T2_COM_MASK       0xCF   /* clears COM21:COM20    */

/** Waveform generation mode */
typedef enum
{
    T2_Normal            = 0x00,
    T2_PWM_PhaseCorrect  = 0x01,
    T2_CTC               = 0x02,
    T2_FastPWM           = 0x03,
}T2_Mode_t;

/** Clock select / prescaler */
typedef enum
{
    T2_NoClock          = 0x00,
    T2_Prescaler_1      = 0x01,
    T2_Prescaler_8      = 0x02,
    T2_Prescaler_32     = 0x03,
    T2_Prescaler_64     = 0x04,
    T2_Prescaler_128    = 0x05,
    T2_Prescaler_256    = 0x06,
    T2_Prescaler_1024   = 0x07,
}T2_ClockSelect_t;

/** OC2 pin (PD7) behavior on compare match */
typedef enum
{
    T2_OC2_Disconnected  = 0x00,
    T2_OC2_Toggle        = 0x01,
    T2_OC2_NonInverting  = 0x02,
    T2_OC2_Inverting     = 0x03,
}T2_CompareOutputMode_t;

/** Interrupt sources */
typedef enum
{
    T2_InterruptOverflow      = 0,
    T2_InterruptCompareMatch  = 1,
}T2_InterruptSource_t;

#define T2_NumberOfInterrupts     2

typedef void (*T2_CallBackFunc_t)(void);

#endif /* T2_PRIVATE */
