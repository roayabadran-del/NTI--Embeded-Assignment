/**
 * @file SystemMap.h
 * @author Team -- Password-Protected Motor Control System
 * @brief Single source of truth for pin assignments across all modules,
 *        same convention as the Smart Home Controller project.
 * @version 0.1
 * @date 2026-08-29
 *
 * @note PIN MAP (chosen to use each port fully, zero wasted or
 *       conflicting pins):
 *   PORT A: Segment display, all 8 pins (a-h)
 *   PORT B: Keypad -- PB0-3=Rows, PB4-7=Columns
 *   PORT C: LCD (4-bit mode) -- PC0=RS PC1=RW PC2=E PC3-6=D4-D7, PC7=spare
 *   PORT D: PD0=Buzzer PD1=RedLED PD2-5=Animation LEDs 0-3
 *           PD6=Motor IN1  PD7=Motor IN2
 *
 * @copyright Copyright (c) 2026
 *
 */
#ifndef APP_SYSTEMMAP_H
#define APP_SYSTEMMAP_H

#include "../Mcal/DIO/DIO_Interface.h"

#define SystemMap_Segment_Group      DIO_GroupA
/* ASSUMPTION: common-cathode 7-segment display (SSD_Cathod). If the
 * actual hardware is common-anode, change this one line to SSD_Anode --
 * everything else in the Segment driver already handles both.
 */
#define SystemMap_Segment_Type       SSD_Cathode

#define SystemMap_Buzzer_Group       DIO_GroupD
#define SystemMap_Buzzer_Pin         DIO_Pin0

#define SystemMap_RedLED_Group       DIO_GroupD
#define SystemMap_RedLED_Pin         DIO_Pin1

#define SystemMap_AnimLED0_Group     DIO_GroupD
#define SystemMap_AnimLED0_Pin       DIO_Pin2
#define SystemMap_AnimLED1_Group     DIO_GroupD
#define SystemMap_AnimLED1_Pin       DIO_Pin3
#define SystemMap_AnimLED2_Group     DIO_GroupD
#define SystemMap_AnimLED2_Pin       DIO_Pin4
#define SystemMap_AnimLED3_Group     DIO_GroupD
#define SystemMap_AnimLED3_Pin       DIO_Pin5

#define SystemMap_Motor_Group        DIO_GroupD
#define SystemMap_Motor_In1Pin       DIO_Pin6
#define SystemMap_Motor_In2Pin       DIO_Pin7

/* Connection-type defaults, kept here so every module reads the same
 * assumption instead of guessing (matches LED_Private.h / Led_Interface.h).
 */
#define SystemMap_RedLED_ConnectionType  LED_SourceConnection
#define SystemMap_AnimLED_ConnectionType LED_SourceConnection

/* Fixed password -- no EEPROM/persistence requirement was given for this
 * project (unlike Smart Home Controller's Authentication module), so this
 * is a compile-time constant. If persistence across power cycles is
 * needed later, this is a one-line swap to EEPROM_ReadBlock() instead.
 */
#define SystemMap_Password { '1','2','3','4' }
#define SystemMap_PasswordLength 4U
#define SystemMap_MaxAttempts    4U

#endif /* APP_SYSTEMMAP_H */
