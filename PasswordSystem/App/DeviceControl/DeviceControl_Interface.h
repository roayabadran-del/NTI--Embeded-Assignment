/**
 * @file DeviceControl_Interface.h
 * @author Team -- Password-Protected Motor Control System
 * @brief Post-unlock application: motor Clockwise/Anti-Clockwise/Stop on
 *        keys 1/2/3 (with matching LCD messages), and a pseudo-random
 *        4-LED animation on key 4.
 * @version 0.1
 * @date 2026-08-29
 *
 * @copyright Copyright (c) 2026
 *
 */
#ifndef DEVICECONTROL_INTERFACE
#define DEVICECONTROL_INTERFACE

#include <stdint.h>
#include "../../Common/BitMath.h"
#include "../../Common/Definition.h"
#include "../../Hal/KeyPad/KeyPad_Interface.h"
#include "../../Hal/LCD/LCD_Interface.h"
#include "../../Hal/LED/Led_Interface.h"
#include "../../Hal/DC_Motor/DCMotor_Interface.h"
#include "../../App/Scheduler/Scheduler_Interface.h"
#include "../SystemMap.h"
#include "DeviceControl_Private.h"
#include "DeviceControl_Config.h"

/** @brief Configure the motor and the 4 animation LED outputs, motor stopped, LEDs off. */
void DEV_Init(void);

/**
 * @brief Scan the keypad once and act on 1/2/3/4 if a new key press is
 *        detected (edge-detected, holding a key does not repeat).
 *        Non-blocking. Register with the Scheduler (e.g. 50ms). Does
 *        nothing until PWD_IsUnlocked() is true -- main.c only calls
 *        this after the password has been accepted.
 */
void DEV_MainFunction(void);

/**
 * @brief Advance the LED animation pattern by one step. No-op unless
 *        currently in Animation mode (key '4' was pressed last).
 *        Register with the Scheduler at DEV_AnimationPeriodMs.
 */
void DEV_AnimationTick(void);

#endif /* DEVICECONTROL_INTERFACE */
