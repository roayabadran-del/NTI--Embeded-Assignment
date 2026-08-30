/**
 * @file DeviceControl_Program.c
 * @author Team -- Password-Protected Motor Control System
 * @brief
 * @version 0.1
 * @date 2026-08-29
 *
 * @copyright Copyright (c) 2026
 *
 */
#include "DeviceControl_Interface.h"

static DEV_Mode_t DEV_CurrentMode   = DEV_ModeIdle;
static uint8_t     DEV_u8PreviousKey = KPD_NotPressed;

/* Small linear congruential generator -- no hardware RNG on this MCU, and
 * true randomness isn't needed for an LED animation, just an
 * unpredictable-looking pattern. Reseeded from the tick count each time
 * animation mode is entered, so the pattern differs run to run.
 */
static uint32_t DEV_u32LcgState = 1UL;

static void DEV_vidLcgAdvance(void)
{
    DEV_u32LcgState = (DEV_u32LcgState*1103515245UL)+12345UL;
}

static void DEV_vidAnimLedWrite(void)
{
    if((DEV_u32LcgState & 0x01UL)!=0UL)
    {
        Led_On(SystemMap_AnimLED0_Group,SystemMap_AnimLED0_Pin,SystemMap_AnimLED_ConnectionType);
    }
    else
    {
        Led_Off(SystemMap_AnimLED0_Group,SystemMap_AnimLED0_Pin,SystemMap_AnimLED_ConnectionType);
    }

    if((DEV_u32LcgState & 0x02UL)!=0UL)
    {
        Led_On(SystemMap_AnimLED1_Group,SystemMap_AnimLED1_Pin,SystemMap_AnimLED_ConnectionType);
    }
    else
    {
        Led_Off(SystemMap_AnimLED1_Group,SystemMap_AnimLED1_Pin,SystemMap_AnimLED_ConnectionType);
    }

    if((DEV_u32LcgState & 0x04UL)!=0UL)
    {
        Led_On(SystemMap_AnimLED2_Group,SystemMap_AnimLED2_Pin,SystemMap_AnimLED_ConnectionType);
    }
    else
    {
        Led_Off(SystemMap_AnimLED2_Group,SystemMap_AnimLED2_Pin,SystemMap_AnimLED_ConnectionType);
    }

    if((DEV_u32LcgState & 0x08UL)!=0UL)
    {
        Led_On(SystemMap_AnimLED3_Group,SystemMap_AnimLED3_Pin,SystemMap_AnimLED_ConnectionType);
    }
    else
    {
        Led_Off(SystemMap_AnimLED3_Group,SystemMap_AnimLED3_Pin,SystemMap_AnimLED_ConnectionType);
    }
}

static void DEV_vidAllAnimLedsOff(void)
{
    Led_Off(SystemMap_AnimLED0_Group,SystemMap_AnimLED0_Pin,SystemMap_AnimLED_ConnectionType);
    Led_Off(SystemMap_AnimLED1_Group,SystemMap_AnimLED1_Pin,SystemMap_AnimLED_ConnectionType);
    Led_Off(SystemMap_AnimLED2_Group,SystemMap_AnimLED2_Pin,SystemMap_AnimLED_ConnectionType);
    Led_Off(SystemMap_AnimLED3_Group,SystemMap_AnimLED3_Pin,SystemMap_AnimLED_ConnectionType);
}

void DEV_Init(void)
{
    DCMotor_Init(SystemMap_Motor_Group,SystemMap_Motor_In1Pin,SystemMap_Motor_In2Pin);

    Led_Init(SystemMap_AnimLED0_Group,SystemMap_AnimLED0_Pin);
    Led_Init(SystemMap_AnimLED1_Group,SystemMap_AnimLED1_Pin);
    Led_Init(SystemMap_AnimLED2_Group,SystemMap_AnimLED2_Pin);
    Led_Init(SystemMap_AnimLED3_Group,SystemMap_AnimLED3_Pin);

    DEV_vidAllAnimLedsOff();
}

void DEV_MainFunction(void)
{
    uint8_t Local_u8Key = KPD_GetPressedKey();

    /* Edge detection: only act the moment a key transitions from
     * "not this key" to "this key" -- holding it down does not repeat.
     */
    if((Local_u8Key!=KPD_NotPressed) && (Local_u8Key!=DEV_u8PreviousKey))
    {
        if(Local_u8Key==(uint8_t)'1')
        {
            DEV_CurrentMode = DEV_ModeIdle;
            DEV_vidAllAnimLedsOff();
            DCMotor_SetState(SystemMap_Motor_Group,SystemMap_Motor_In1Pin,SystemMap_Motor_In2Pin,DCMotor_ClockWise);
            LCD_MoveTo(0U,0U);
            LCD_WriteString((uint8_t*)"Clockwise Move  ");
            LCD_MoveTo(1U,0U);
            LCD_WriteString((uint8_t*)"                ");
        }
        else if(Local_u8Key==(uint8_t)'2')
        {
            DEV_CurrentMode = DEV_ModeIdle;
            DEV_vidAllAnimLedsOff();
            DCMotor_SetState(SystemMap_Motor_Group,SystemMap_Motor_In1Pin,SystemMap_Motor_In2Pin,DCMotor_AntiClockWise);
            LCD_MoveTo(0U,0U);
            LCD_WriteString((uint8_t*)"Anti-CW Move    ");
            LCD_MoveTo(1U,0U);
            LCD_WriteString((uint8_t*)"                ");
        }
        else if(Local_u8Key==(uint8_t)'3')
        {
            DEV_CurrentMode = DEV_ModeIdle;
            DEV_vidAllAnimLedsOff();
            DCMotor_SetState(SystemMap_Motor_Group,SystemMap_Motor_In1Pin,SystemMap_Motor_In2Pin,DCMotor_Stop);
            LCD_MoveTo(0U,0U);
            LCD_WriteString((uint8_t*)"Motor Stopped   ");
            LCD_MoveTo(1U,0U);
            LCD_WriteString((uint8_t*)"                ");
        }
        else if(Local_u8Key==(uint8_t)'4')
        {
            DEV_CurrentMode = DEV_ModeAnimation;
            /* reseed from the current tick count so the pattern differs
             * each time animation mode is entered
             */
            DEV_u32LcgState = SCHED_GetTickCount()+1UL;
            LCD_MoveTo(0U,0U);
            LCD_WriteString((uint8_t*)"LED Animation   ");
            LCD_MoveTo(1U,0U);
            LCD_WriteString((uint8_t*)"1/2/3 to stop   ");
        }
        else
        {
            // key not relevant here
        }
    }
    else
    {
        // no new key press this tick
    }

    DEV_u8PreviousKey = Local_u8Key;
}

void DEV_AnimationTick(void)
{
    if(DEV_CurrentMode==DEV_ModeAnimation)
    {
        DEV_vidLcgAdvance();
        DEV_vidAnimLedWrite();
    }
    else
    {
        // Not in animation mode: nothing to do
    }
}
