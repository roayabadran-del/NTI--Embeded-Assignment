/**
 * @file PasswordLock_Program.c
 * @author Team -- Password-Protected Motor Control System
 * @brief
 * @version 0.1
 * @date 2026-08-29
 *
 * @copyright Copyright (c) 2026
 *
 */
#include "PasswordLock_Interface.h"

static PWD_State_t PWD_CurrentState   = PWD_StateEntering;
static uint8_t      PWD_au8Entry[SystemMap_PasswordLength];
static uint8_t      PWD_u8EntryIndex  = 0U;
static uint8_t      PWD_u8Attempts    = 0U;
static uint8_t      PWD_u8Unlocked    = 0U;
static uint8_t      PWD_u8PreviousKey = KPD_NotPressed;
static uint8_t      PWD_u8RedLedState = 0U;

static const uint8_t PWD_au8StoredPassword[SystemMap_PasswordLength] = SystemMap_Password;

void PWD_Init(void)
{
    SSD_Init(SystemMap_Segment_Group);
    Buzzer_Init(SystemMap_Buzzer_Group,SystemMap_Buzzer_Pin);
    Led_Init(SystemMap_RedLED_Group,SystemMap_RedLED_Pin);

    SSD_DisplayNumber(SystemMap_Segment_Group,SystemMap_Segment_Type,0U);

    LCD_MoveTo(0U,0U);
    LCD_WriteString((uint8_t*)"Enter Password: ");
    LCD_MoveTo(1U,0U);
    LCD_WriteString((uint8_t*)"                ");
}

void PWD_MainFunction(void)
{
    if(PWD_CurrentState==PWD_StateEntering)
    {
        uint8_t Local_u8Key = KPD_GetPressedKey();

        /* Edge detection: only act the moment a key transitions from
         * "not this key" to "this key" -- holding it down does not repeat.
         */
        if((Local_u8Key!=KPD_NotPressed) && (Local_u8Key!=PWD_u8PreviousKey))
        {
            if(Local_u8Key==(uint8_t)'C')
            {
                /* Clear current entry, start over */
                PWD_u8EntryIndex = 0U;
                LCD_MoveTo(1U,0U);
                LCD_WriteString((uint8_t*)"                ");
            }
            else if((Local_u8Key>=(uint8_t)'0') && (Local_u8Key<=(uint8_t)'9')
                    && (PWD_u8EntryIndex<SystemMap_PasswordLength))
            {
                PWD_au8Entry[PWD_u8EntryIndex] = Local_u8Key;
                LCD_MoveTo(1U,(uint8_t)PWD_u8EntryIndex);
                LCD_WriteCharacter((uint8_t)'*'); /* mask the digit on-screen */
                PWD_u8EntryIndex++;

                if(PWD_u8EntryIndex>=SystemMap_PasswordLength)
                {
                    uint8_t Local_u8Match = 1U;
                    uint8_t Local_u8Index;

                    for(Local_u8Index=0U; Local_u8Index<SystemMap_PasswordLength; Local_u8Index++)
                    {
                        if(PWD_au8Entry[Local_u8Index]!=PWD_au8StoredPassword[Local_u8Index])
                        {
                            Local_u8Match = 0U;
                        }
                        else
                        {
                            // digit matches, keep checking
                        }
                    }

                    if(Local_u8Match==1U)
                    {
                        PWD_u8Unlocked = 1U;
                        PWD_CurrentState = PWD_StateUnlocked;
                        LCD_MoveTo(0U,0U);
                        LCD_WriteString((uint8_t*)"Access Granted  ");
                        LCD_MoveTo(1U,0U);
                        LCD_WriteString((uint8_t*)"                ");
                    }
                    else
                    {
                        PWD_u8Attempts++;
                        SSD_DisplayNumber(SystemMap_Segment_Group,SystemMap_Segment_Type,PWD_u8Attempts);

                        if(PWD_u8Attempts>=SystemMap_MaxAttempts)
                        {
                            PWD_CurrentState = PWD_StateBlocked;
                            Buzzer_On(SystemMap_Buzzer_Group,SystemMap_Buzzer_Pin);
                            LCD_MoveTo(0U,0U);
                            LCD_WriteString((uint8_t*)"BLOCKED         ");
                            LCD_MoveTo(1U,0U);
                            LCD_WriteString((uint8_t*)"                ");
                        }
                        else
                        {
                            LCD_MoveTo(0U,0U);
                            LCD_WriteString((uint8_t*)"Wrong, Retry:   ");
                            LCD_MoveTo(1U,0U);
                            LCD_WriteString((uint8_t*)"                ");
                        }

                        PWD_u8EntryIndex = 0U;
                    }
                }
                else
                {
                    // still collecting digits
                }
            }
            else
            {
                // key not relevant while entering a password
            }
        }
        else
        {
            // no new key press this tick
        }

        PWD_u8PreviousKey = Local_u8Key;
    }
    else
    {
        // Unlocked (DeviceControl now owns the keypad) or Blocked
        // (system stays locked until power is cycled, per spec): keypad
        // input is ignored here either way.
    }
}

void PWD_BlockedTick(void)
{
    if(PWD_CurrentState==PWD_StateBlocked)
    {
        if(PWD_u8RedLedState==0U)
        {
            Led_On(SystemMap_RedLED_Group,SystemMap_RedLED_Pin,SystemMap_RedLED_ConnectionType);
            PWD_u8RedLedState = 1U;
        }
        else
        {
            Led_Off(SystemMap_RedLED_Group,SystemMap_RedLED_Pin,SystemMap_RedLED_ConnectionType);
            PWD_u8RedLedState = 0U;
        }
    }
    else
    {
        // Not blocked: nothing to flicker
    }
}

uint8_t PWD_IsUnlocked(void)
{
    return PWD_u8Unlocked;
}

uint8_t PWD_IsBlocked(void)
{
    uint8_t Local_u8Result;

    if(PWD_CurrentState==PWD_StateBlocked)
    {
        Local_u8Result = 1U;
    }
    else
    {
        Local_u8Result = 0U;
    }

    return Local_u8Result;
}
