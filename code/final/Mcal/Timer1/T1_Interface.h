#ifndef T1_INTERFACE
#define T1_INTERFACE
#include <stdint.h>
#include "../../Common/BitMath.h"
#include "../../Common/Definition.h"
#include "../Atmega32Register.h"
#include "T1_Private.h"
#include "T1_Config.h"

/*API's*/
void T1_Init(uint8_t Copy_u8Mode, uint8_t Copy_u8Prescaler);
void T1_DeInit(void);

void T1_Start(void);
void T1_Stop(void);

void T1_SetTimerValue(uint16_t Copy_u16TimerValue);
void T1_GetTimerValue(uint16_t *Copy_pu16TimerValue);

void T1_SetCompareValue(uint8_t Copy_u8Channel, uint16_t Copy_u16CompareValue);
void T1_GetCompareValue(uint8_t Copy_u8Channel, uint16_t *Copy_pu16CompareValue);

void T1_SetCompareOutputMode(uint8_t Copy_u8Channel, uint8_t Copy_u8CompareMode);

void T1_SetICRValue(uint16_t Copy_u16ICRValue);
void T1_GetICRValue(uint16_t *Copy_pu16ICRValue);

void T1_SetInputCaptureEdge(uint8_t Copy_u8Edge);
void T1_InputCaptureNoiseCanceler(uint8_t Copy_u8Enable);

void T1_EnableInterrupt(uint8_t Copy_u8InterruptSource);
void T1_DisableInterrupt(uint8_t Copy_u8InterruptSource);

void T1_SetCallBack(void (*Copy_pfLocalFunction)(void), uint8_t Copy_u8InterruptSource);

/*ISR*/
/*Timer1 Input Capture*/
void __vector_6()   __attribute__((signal));
/*Timer1 Compare Match A*/
void __vector_7()   __attribute__((signal));
/*Timer1 Compare Match B*/
void __vector_8()   __attribute__((signal));
/*Timer1 Overflow*/
void __vector_9()   __attribute__((signal));

#endif /* T1_INTERFACE */
