#include "T2_Interface.h"

static T2_CallBackFunc_t T2_CallBackArr[T2_NumberOfInterrupts] = {NULL, NULL};
static uint8_t T2_CurrentPrescaler = T2_NoClock;

/*API's*/
void T2_Init(uint8_t Copy_u8Mode, uint8_t Copy_u8Prescaler)
{
    /* Waveform Generation Mode */
    if(Copy_u8Mode <= T2_FastPWM)
    {
        ClearBit(TCCR2_Reg, Bit_WGM20);
        ClearBit(TCCR2_Reg, Bit_WGM21);

        switch(Copy_u8Mode)
        {
            case T2_Normal: break;
            case T2_PWM_PhaseCorrect: SetBit(TCCR2_Reg, Bit_WGM20); break;
            case T2_CTC: SetBit(TCCR2_Reg, Bit_WGM21); break;
            case T2_FastPWM:
                SetBit(TCCR2_Reg, Bit_WGM20);
                SetBit(TCCR2_Reg, Bit_WGM21);
                break;
            default: break;
        }
    }
    else
    {
        /* Error */
    }

    /* Prescaler (also starts the timer) */
    if(Copy_u8Prescaler <= T2_Prescaler_1024)
    {
        TCCR2_Reg &= T2_CS_MASK;
        TCCR2_Reg |= Copy_u8Prescaler;
        T2_CurrentPrescaler = Copy_u8Prescaler;
    }
    else
    {
        /* Error */
    }

    TCNT2_Reg = T2_INITIAL_TCNT2_VALUE;
    OCR2_Reg  = T2_INITIAL_OCR2_VALUE;
}

void T2_DeInit(void)
{
    TCCR2_Reg = 0x00;
    TCNT2_Reg = 0x00;
    OCR2_Reg  = 0x00;
    ClearBit(TIMSK_Reg, Bit_TOIE2);
    ClearBit(TIMSK_Reg, Bit_OCIE2);
    T2_CurrentPrescaler = T2_NoClock;
}

void T2_Start(void)
{
    TCCR2_Reg &= T2_CS_MASK;
    TCCR2_Reg |= T2_CurrentPrescaler;
}

void T2_Stop(void)
{
    TCCR2_Reg &= T2_CS_MASK;
}

void T2_SetTimerValue(uint8_t Copy_u8TimerValue)
{
    TCNT2_Reg = Copy_u8TimerValue;
}

void T2_GetTimerValue(uint8_t *Copy_pu8TimerValue)
{
    if(Copy_pu8TimerValue != NULL)
    {
        *Copy_pu8TimerValue = TCNT2_Reg;
    }
    else
    {
        /* Error */
    }
}

void T2_SetCompareValue(uint8_t Copy_u8CompareValue)
{
    OCR2_Reg = Copy_u8CompareValue;
}

void T2_GetCompareValue(uint8_t *Copy_pu8CompareValue)
{
    if(Copy_pu8CompareValue != NULL)
    {
        *Copy_pu8CompareValue = OCR2_Reg;
    }
    else
    {
        /* Error */
    }
}

void T2_SetCompareOutputMode(uint8_t Copy_u8CompareMode)
{
    if(Copy_u8CompareMode <= T2_OC2_Inverting)
    {
        TCCR2_Reg &= T2_COM_MASK;
        TCCR2_Reg |= (Copy_u8CompareMode << Bit_COM20);
    }
    else
    {
        /* Error */
    }
}

void T2_EnableInterrupt(uint8_t Copy_u8InterruptSource)
{
    switch(Copy_u8InterruptSource)
    {
        case T2_InterruptOverflow:     SetBit(TIMSK_Reg, Bit_TOIE2); break;
        case T2_InterruptCompareMatch: SetBit(TIMSK_Reg, Bit_OCIE2); break;
        default: /* Error */ break;
    }
}

void T2_DisableInterrupt(uint8_t Copy_u8InterruptSource)
{
    switch(Copy_u8InterruptSource)
    {
        case T2_InterruptOverflow:     ClearBit(TIMSK_Reg, Bit_TOIE2); break;
        case T2_InterruptCompareMatch: ClearBit(TIMSK_Reg, Bit_OCIE2); break;
        default: /* Error */ break;
    }
}

void T2_SetCallBack(void (*Copy_pfLocalFunction)(void), uint8_t Copy_u8InterruptSource)
{
    if(Copy_pfLocalFunction != NULL)
    {
        if(Copy_u8InterruptSource < T2_NumberOfInterrupts)
        {
            T2_CallBackArr[Copy_u8InterruptSource] = Copy_pfLocalFunction;
        }
        else
        {
            /* Error */
        }
    }
    else
    {
        /* Error */
    }
}

/*ISR*/
void __vector_4()   /* Timer2 Compare Match */
{
    if(T2_CallBackArr[T2_InterruptCompareMatch] != NULL)
    {
        T2_CallBackArr[T2_InterruptCompareMatch]();
    }
}

void __vector_5()   /* Timer2 Overflow */
{
    if(T2_CallBackArr[T2_InterruptOverflow] != NULL)
    {
        T2_CallBackArr[T2_InterruptOverflow]();
    }
}
