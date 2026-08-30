#ifndef T1_PRIVATE
#define T1_PRIVATE

/* TCCR1A bits */
#define Bit_COM1A1    7
#define Bit_COM1A0    6
#define Bit_COM1B1    5
#define Bit_COM1B0    4
#define Bit_FOC1A     3
#define Bit_FOC1B     2
#define Bit_WGM11     1
#define Bit_WGM10     0

/* TCCR1B bits */
#define Bit_ICNC1     7
#define Bit_ICES1     6
#define Bit_WGM13     4
#define Bit_WGM12     3
#define Bit_CS12      2
#define Bit_CS11      1
#define Bit_CS10      0

/* TIMSK bits (Timer1 related) */
#define Bit_TICIE1    5
#define Bit_OCIE1A    4
#define Bit_OCIE1B    3
#define Bit_TOIE1     2

/* TIFR bits (Timer1 related) */
#define Bit_ICF1      5
#define Bit_OCF1A     4
#define Bit_OCF1B     3
#define Bit_TOV1      2

/* Masks */
#define T1_CS_MASK        0xF8   /* clears CS12:CS11:CS10 in TCCR1B */
#define T1_COM1A_MASK     0x3F   /* clears COM1A1:COM1A0 in TCCR1A */
#define T1_COM1B_MASK     0xCF   /* clears COM1B1:COM1B0 in TCCR1A */
#define T1_WGM1A_MASK     0xFC   /* clears WGM11:WGM10  in TCCR1A */
#define T1_WGM1B_MASK     0xE7   /* clears WGM13:WGM12  in TCCR1B */

/** Waveform generation mode (WGM13:WGM10) */
typedef enum
{
    T1_Normal                    = 0x00,
    T1_PWM_PhaseCorrect_8bit     = 0x01,
    T1_PWM_PhaseCorrect_9bit     = 0x02,
    T1_PWM_PhaseCorrect_10bit    = 0x03,
    T1_CTC                       = 0x04,
    T1_FastPWM_8bit              = 0x05,
    T1_FastPWM_9bit              = 0x06,
    T1_FastPWM_10bit             = 0x07,
    T1_PWM_PF_Correct_ICR1       = 0x08,
    T1_PWM_PF_Correct_OCR1A      = 0x09,
    T1_PWM_PhaseCorrect_ICR1     = 0x0A,
    T1_PWM_PhaseCorrect_OCR1A    = 0x0B,
    T1_CTC_ICR1                  = 0x0C,
    /* 0x0D Reserved */
    T1_FastPWM_ICR1              = 0x0E,
    T1_FastPWM_OCR1A             = 0x0F,
}T1_Mode_t;

/** Clock select / prescaler */
typedef enum
{
    T1_NoClock                  = 0x00,
    T1_Prescaler_1              = 0x01,
    T1_Prescaler_8              = 0x02,
    T1_Prescaler_64             = 0x03,
    T1_Prescaler_256            = 0x04,
    T1_Prescaler_1024           = 0x05,
    T1_ExtClock_Falling         = 0x06,
    T1_ExtClock_Rising          = 0x07,
}T1_ClockSelect_t;

/** OC1A / OC1B pin behavior on compare match */
typedef enum
{
    T1_OC_Disconnected  = 0x00,
    T1_OC_Toggle        = 0x01,
    T1_OC_NonInverting  = 0x02,
    T1_OC_Inverting     = 0x03,
}T1_CompareOutputMode_t;

/** Compare channel selection */
typedef enum
{
    T1_Channel_A        = 0,
    T1_Channel_B        = 1,
}T1_Channel_t;

/** Interrupt sources */
typedef enum
{
    T1_InterruptOverflow      = 0,
    T1_InterruptCompareMatchA = 1,
    T1_InterruptCompareMatchB = 2,
    T1_InterruptInputCapture  = 3,
}T1_InterruptSource_t;

/** Input capture edge selection */
typedef enum
{
    T1_IC_Edge_Falling  = 0,
    T1_IC_Edge_Rising   = 1,
}T1_IC_Edge_t;

#define T1_NumberOfInterrupts     4

typedef void (*T1_CallBackFunc_t)(void);

#endif /* T1_PRIVATE */
