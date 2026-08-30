#include "T1_Interface.h"

static T1_CallBackFunc_t T1_CallBackArr[T1_NumberOfInterrupts] = {NULL, NULL, NULL, NULL};
static uint8_t T1_CurrentPrescaler = T1_NoClock;

/*API's*/
void T1_Init(uint8_t Copy_u8Mode, uint8_t Copy_u8Prescaler)
{
    /* Clear WGM bits in both TCCR1A and TCCR1B */
    TCCR1A_Reg &= T1_WGM1A_MASK;
    TCCR1B_Reg &= T1_WGM1B_MASK;

    /* Set Waveform Generation Mode */
    /* WGM11:WGM10 from mode bits [1:0] into TCCR1A */
    /* WGM13:WGM12 from mode bits [3:2] into TCCR1B */
    TCCR1A_Reg |= (Copy_u8Mode & 0x03);
    TCCR1B_Reg |= ((Copy_u8Mode >> 2) & 0x03) << Bit_WGM12;

    /* Prescaler (also starts the timer) */
    if(Copy_u8Prescaler <= T1_ExtClock_Rising)
    {
        TCCR1B_Reg &= T1_CS_MASK;
        TCCR1B_Reg |= Copy_u8Prescaler;
        T1_CurrentPrescaler = Copy_u8Prescaler;
    }
    else
    {
        /* Error */
    }

    TCNT1_Reg  = T1_INITIAL_TCNT1_VALUE;
    OCR1A_Reg  = T1_INITIAL_OCR1A_VALUE;
    OCR1B_Reg  = T1_INITIAL_OCR1B_VALUE;
    ICR1_Reg   = T1_INITIAL_ICR1_VALUE;
}

void T1_DeInit(void)
{
    TCCR1A_Reg = 0x00;
    TCCR1B_Reg = 0x00;
    TCNT1_Reg  = 0x0000;
    OCR1A_Reg  = 0x0000;
    OCR1B_Reg  = 0x0000;
    ICR1_Reg   = 0x0000;
    ClearBit(TIMSK_Reg, Bit_TOIE1);
    ClearBit(TIMSK_Reg, Bit_OCIE1A);
    ClearBit(TIMSK_Reg, Bit_OCIE1B);
    ClearBit(TIMSK_Reg, Bit_TICIE1);
    T1_CurrentPrescaler = T1_NoClock;
}

void T1_Start(void)
{
    TCCR1B_Reg &= T1_CS_MASK;
    TCCR1B_Reg |= T1_CurrentPrescaler;
}

void T1_Stop(void)
{
    TCCR1B_Reg &= T1_CS_MASK;
}

void T1_SetTimerValue(uint16_t Copy_u16TimerValue)
{
    TCNT1_Reg = Copy_u16TimerValue;
}

void T1_GetTimerValue(uint16_t *Copy_pu16TimerValue)
{
    if(Copy_pu16TimerValue != NULL)
    {
        *Copy_pu16TimerValue = TCNT1_Reg;
    }
    else
    {
        /* Error */
    }
}

void T1_SetCompareValue(uint8_t Copy_u8Channel, uint16_t Copy_u16CompareValue)
{
    if(Copy_u8Channel == T1_Channel_A)
    {
        OCR1A_Reg = Copy_u16CompareValue;
    }
    else if(Copy_u8Channel == T1_Channel_B)
    {
        OCR1B_Reg = Copy_u16CompareValue;
    }
    else
    {
        /* Error */
    }
}

void T1_GetCompareValue(uint8_t Copy_u8Channel, uint16_t *Copy_pu16CompareValue)
{
    if(Copy_pu16CompareValue != NULL)
    {
        if(Copy_u8Channel == T1_Channel_A)
        {
            *Copy_pu16CompareValue = OCR1A_Reg;
        }
        else if(Copy_u8Channel == T1_Channel_B)
        {
            *Copy_pu16CompareValue = OCR1B_Reg;
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

void T1_SetCompareOutputMode(uint8_t Copy_u8Channel, uint8_t Copy_u8CompareMode)
{
    if(Copy_u8CompareMode <= T1_OC_Inverting)
    {
        if(Copy_u8Channel == T1_Channel_A)
        {
            TCCR1A_Reg &= T1_COM1A_MASK;
            TCCR1A_Reg |= (Copy_u8CompareMode << Bit_COM1A0);
        }
        else if(Copy_u8Channel == T1_Channel_B)
        {
            TCCR1A_Reg &= T1_COM1B_MASK;
            TCCR1A_Reg |= (Copy_u8CompareMode << Bit_COM1B0);
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

void T1_SetICRValue(uint16_t Copy_u16ICRValue)
{
    ICR1_Reg = Copy_u16ICRValue;
}

void T1_GetICRValue(uint16_t *Copy_pu16ICRValue)
{
    if(Copy_pu16ICRValue != NULL)
    {
        *Copy_pu16ICRValue = ICR1_Reg;
    }
    else
    {
        /* Error */
    }
}

void T1_SetInputCaptureEdge(uint8_t Copy_u8Edge)
{
    if(Copy_u8Edge == T1_IC_Edge_Rising)
    {
        SetBit(TCCR1B_Reg, Bit_ICES1);
    }
    else
    {
        ClearBit(TCCR1B_Reg, Bit_ICES1);
    }
}

void T1_InputCaptureNoiseCanceler(uint8_t Copy_u8Enable)
{
    if(Copy_u8Enable != 0)
    {
        SetBit(TCCR1B_Reg, Bit_ICNC1);
    }
    else
    {
        ClearBit(TCCR1B_Reg, Bit_ICNC1);
    }
}

void T1_EnableInterrupt(uint8_t Copy_u8InterruptSource)
{
    switch(Copy_u8InterruptSource)
    {
        case T1_InterruptOverflow:      SetBit(TIMSK_Reg, Bit_TOIE1);  break;
        case T1_InterruptCompareMatchA: SetBit(TIMSK_Reg, Bit_OCIE1A); break;
        case T1_InterruptCompareMatchB: SetBit(TIMSK_Reg, Bit_OCIE1B); break;
        case T1_InterruptInputCapture:  SetBit(TIMSK_Reg, Bit_TICIE1); break;
        default: /* Error */ break;
    }
}

void T1_DisableInterrupt(uint8_t Copy_u8InterruptSource)
{
    switch(Copy_u8InterruptSource)
    {
        case T1_InterruptOverflow:      ClearBit(TIMSK_Reg, Bit_TOIE1);  break;
        case T1_InterruptCompareMatchA: ClearBit(TIMSK_Reg, Bit_OCIE1A); break;
        case T1_InterruptCompareMatchB: ClearBit(TIMSK_Reg, Bit_OCIE1B); break;
        case T1_InterruptInputCapture:  ClearBit(TIMSK_Reg, Bit_TICIE1); break;
        default: /* Error */ break;
    }
}

void T1_SetCallBack(void (*Copy_pfLocalFunction)(void), uint8_t Copy_u8InterruptSource)
{
    if(Copy_pfLocalFunction != NULL)
    {
        if(Copy_u8InterruptSource < T1_NumberOfInterrupts)
        {
            T1_CallBackArr[Copy_u8InterruptSource] = Copy_pfLocalFunction;
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
void __vector_6()   /* Timer1 Input Capture */
{
    if(T1_CallBackArr[T1_InterruptInputCapture] != NULL)
    {
        T1_CallBackArr[T1_InterruptInputCapture]();
    }
}

void __vector_7()   /* Timer1 Compare Match A */
{
    if(T1_CallBackArr[T1_InterruptCompareMatchA] != NULL)
    {
        T1_CallBackArr[T1_InterruptCompareMatchA]();
    }
}

void __vector_8()   /* Timer1 Compare Match B */
{
    if(T1_CallBackArr[T1_InterruptCompareMatchB] != NULL)
    {
        T1_CallBackArr[T1_InterruptCompareMatchB]();
    }
}

void __vector_9()   /* Timer1 Overflow */
{
    if(T1_CallBackArr[T1_InterruptOverflow] != NULL)
    {
        T1_CallBackArr[T1_InterruptOverflow]();
    }
}
