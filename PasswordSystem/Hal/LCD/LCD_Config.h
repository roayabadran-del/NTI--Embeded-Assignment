/**
 * @file LCD_Config.h
 * @author Hesham Ahmed (Hisham4Ahmed@gmail.com)
 * @brief 
 * @version 0.1
 * @date 2026-08-24
 * 
 * @copyright Copyright (c) 2026
 * 
 */
#ifndef LCD_CONFIG
#define LCD_CONFIG
/* This project's LCD is on PORT C, 4-bit mode (RS,RW,E + D4-D7 = 7 of 8
 * pins), leaving PC7 spare -- see the full project pin map note in
 * App/SystemMap.h. Reused from the Smart Home Controller project's
 * verified LCD driver, only the pin assignments below changed for this
 * project's different wiring.
 */
#define LCD_TypeMode Lcd_4bitMode

// PreConfiguration -> Compile time 
#include "../../Mcal/DIO/DIO_Interface.h"

#define RSPin         DIO_Pin0
#define RSGroup       DIO_GroupC

#define RWPin         DIO_Pin1
#define RWGroup       DIO_GroupC

#define EPin         DIO_Pin2
#define EGroup       DIO_GroupC

#if LCD_TypeMode==Lcd_8bitMode
    #define DataGroup   DIO_GroupD  
#elif LCD_TypeMode==Lcd_4bitMode
    #define DataGroup   DIO_GroupC
    #define D4Pin       DIO_Pin3
    #define D5Pin       DIO_Pin4
    #define D6Pin       DIO_Pin5
    #define D7Pin       DIO_Pin6
#endif
/**
Lcd_4Bit2Line5x8F 
Lcd_4Bit2Line5x11F
Lcd_4Bit1Line5x8F 
Lcd_4Bit1Line5x11F
Lcd_8Bit2Line5x8F 
Lcd_8Bit2Line5x11F
Lcd_8Bit1Line5x8F 
Lcd_8Bit1Line5x11F
*/
/* NOTE: the project's LCD hardware is a 16x2 (2-line) display, and we are
 * now in 4-bit mode (see LCD_TypeMode above) -- so this must be one of
 * the Lcd_4Bit2Line... options, not the previous 8-bit 1-line setting.
 */
#define Lcd_FunctionSet  Lcd_4Bit2Line5x8F 
/**
Lcd_DisplayOff               
Lcd_DisplayOnCursorOff       
Lcd_DisplayOnCursorOnBlinkOff
Lcd_DisplayOnCursorOnBlinkOn 
*/
#define Lcd_DisplayOnOFF Lcd_DisplayOnCursorOnBlinkOn


/**
Lcd_EntryMode_DecNoShift  
Lcd_EntryMode_DecShift    
Lcd_EntryMode_IncNoShift  
Lcd_EntryMode_IncShift    
*/
#define Lcd_EntryMode    Lcd_EntryMode_IncNoShift
#endif /* LCD_CONFIG */
