#ifndef T2_INTERFACE
#define T2_INTERFACE
#include <stdint.h>
#include "../../Common/BitMath.h"
#include "../../Common/Definition.h"
#include "../Atmega32Register.h"
#include "T2_Private.h"
#include "T2_Config.h"

/*API's*/
void T2_Init(uint8_t Copy_u8Mode, uint8_t Copy_u8Prescaler);
void T2_DeInit(void);

void T2_Start(void);
void T2_Stop(void);

void T2_SetTimerValue(uint8_t Copy_u8TimerValue);
void T2_GetTimerValue(uint8_t *Copy_pu8TimerValue);

void T2_SetCompareValue(uint8_t Copy_u8CompareValue);
void T2_GetCompareValue(uint8_t *Copy_pu8CompareValue);

void T2_SetCompareOutputMode(uint8_t Copy_u8CompareMode);

void T2_EnableInterrupt(uint8_t Copy_u8InterruptSource);
void T2_DisableInterrupt(uint8_t Copy_u8InterruptSource);

void T2_SetCallBack(void (*Copy_pfLocalFunction)(void), uint8_t Copy_u8InterruptSource);

/*ISR*/
/*Timer2 Compare Match*/
void __vector_4()   __attribute__((signal));
/*Timer2 Overflow*/
void __vector_5()   __attribute__((signal));

#endif /* T2_INTERFACE */
