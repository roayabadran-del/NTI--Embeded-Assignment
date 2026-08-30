/**
 * @file PasswordLock_Interface.h
 * @author Team -- Password-Protected Motor Control System
 * @brief Keypad password entry, 7-segment attempt counter, and lockout
 *        (buzzer + flickering red LED) after 4 wrong attempts.
 * @version 0.1
 * @date 2026-08-29
 *
 * @copyright Copyright (c) 2026
 *
 */
#ifndef PASSWORDLOCK_INTERFACE
#define PASSWORDLOCK_INTERFACE

#include <stdint.h>
#include "../../Common/BitMath.h"
#include "../../Common/Definition.h"
#include "../../Hal/KeyPad/KeyPad_Interface.h"
#include "../../Hal/LCD/LCD_Interface.h"
#include "../../Hal/Segment/Segment_Interface.h"
#include "../../Hal/Buzzer/Buzzer_Interface.h"
#include "../../Hal/LED/Led_Interface.h"
#include "../SystemMap.h"
#include "PasswordLock_Private.h"
#include "PasswordLock_Config.h"

/** @brief Configure Segment/Buzzer/Red LED outputs and show the initial "Enter Password" prompt. */
void PWD_Init(void);

/**
 * @brief Scan the keypad once and advance password entry if a new key
 *        press is detected (edge-detected, holding a key does not
 *        repeat). Non-blocking. Register with the Scheduler (e.g. 50ms).
 *        Does nothing once blocked or once unlocked.
 */
void PWD_MainFunction(void);

/**
 * @brief Toggle the red LED. Non-blocking flicker driver -- only has any
 *        effect while the system is in the Blocked state. Register with
 *        the Scheduler at PWD_BlinkPeriodMs regardless of state; it is a
 *        no-op when not blocked.
 */
void PWD_BlockedTick(void);

/** @brief 1 once the correct password has been entered, 0 otherwise. */
uint8_t PWD_IsUnlocked(void);

/** @brief 1 once the system has hit the max attempt count and is locked out. */
uint8_t PWD_IsBlocked(void);

#endif /* PASSWORDLOCK_INTERFACE */
