#include "ADC_Interface.h"


// Reg =(Reg &~Mask)|Value
// 76543210
// 00001000
void ADC_Init(const ADC_Config_t * Config)
{
    if(Config!=NULL)
    {
        // 1- Confiure Voltage reference 6 ,7 
        ADMUX_Reg = (ADMUX_Reg&~ADMUX_VrefMask)|(Config->Vref);
        // 2- Configure Adjust
        ADMUX_Reg = (ADMUX_Reg&~ADMUX_AdjustMask)|(Config->Adjust);
        // 3- Configure Clock Select 
        ADCSRA_Reg = (ADCSRA_Reg&~ADCSRA_PrescallerMask)|(Config->Prescaler);
        // 4- Configure AutoMode 
        if(Config->Mode==ADC_AutoConversionMode)
        {
            SetBit(ADCSRA_Reg,Bit_ADATE);
            // 4.1 - Configure Trigger Source 
            SFIOR_Reg = (SFIOR_Reg&~SFIOR_TriggerSourceMask)|(Config->TriggerSource);
        }
        else 
        {
            ClearBit(ADCSRA_Reg,Bit_ADATE);
        }
        // 6- Interrupt State 
        ADCSRA_Reg = (ADCSRA_Reg&~ADCSRA_InterruptMask)|(Config->Interrupt);
        // 7- Enable 
        ADCSRA_Reg = (ADCSRA_Reg&~ADCSRA_StateMask)|(Config->State);
    }
}
#define ADMUX_ChannelMask  0x1F
uint16_t ADC_ReadChannelPolling(uint8_t ADC_Channel)
{
    // 76543210
    // 00011111
    uint16_t DigitalVolt = 0 ;
    // 1- Update Channel 
    ADMUX_Reg = (ADMUX_Reg&~ADMUX_ChannelMask)|(ADC_Channel&~0b11100000);
    // 2- Start Conversion -> 
    SetBit(ADCSRA_Reg,Bit_ADSC);
    // 3- wait for the Conversion to complete (Pollingon Flag on )
    while(ReadBit(ADCSRA_Reg,Bit_ADIF)== 0)
    {
        // waiting 
    }
    // 4- Clear Manual for Flag 
    SetBit(ADCSRA_Reg,Bit_ADIF);
    // 5- Read Result Check Adjust
    if(ReadBit(ADMUX_Reg,Bit_ADLAR)==ADC_LeftAdjust)
    {
        DigitalVolt = (ADCL_Reg>>6)|(ADCH_Reg<<2); // @todo Search 
    }
    else 
    {
        DigitalVolt = ADCData_Reg;
    }
        return DigitalVolt;
}

void ADC_StartConversionInterrupt(uint8_t ADC_Channel)
{
    ADMUX_Reg = (ADMUX_Reg&~ADMUX_ChannelMask)|(ADC_Channel&~0b11100000);
    SetBit(ADCSRA_Reg,Bit_ADSC);
}

/**/
void ADC_SetCallBack(void(*PF)(uint16_t ADCResult))
{
    /*@todo*/
}

void __vector_16()
{
    uint16_t Digitalvolt=0;
    if(ReadBit(ADMUX_Reg,Bit_ADLAR)==ADC_LeftAdjust)
    {
        Digitalvolt = (ADCL_Reg>>6)|(ADCH_Reg<<2);
    }
    else 
    {
        Digitalvolt= ADCData_Reg;
    }
    /* Call the Globale Pointer -> Video Call Back
        @todo
    */

}