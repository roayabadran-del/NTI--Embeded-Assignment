/**
 * @file LCD_Program.c
 * @author Hesham Ahmed (Hisham4Ahmed@gmail.com)
 * @brief 
 * @version 0.1
 * @date 2026-08-24
 * 
 * @copyright Copyright (c) 2026
 * 
 */

#include "LCD_Interface.h"

void LCD_Init()
{

    /*Direction*/
    // RS -> Output
    DIO_DirectionSelectforPin(RSGroup,RSPin,DIO_Outputfor1Pin);
    // RW -> Output 
    DIO_DirectionSelectforPin(RWGroup,RWPin,DIO_Outputfor1Pin);
    // E  -> Output
    DIO_DirectionSelectforPin(EGroup,EPin,DIO_Outputfor1Pin);
    #if LCD_TypeMode==Lcd_8bitMode
        // DataPin -> All Output 
        DIO_DirectionSelectforGroup(DataGroup,DIO_Outputfor1Group);

        /*8bit Init*/
        // wait for 35msec 
        _delay_ms(35);
        // Function Set 
        // 0 0 1 DL N F x x
        // 0 0 1 1
        LCD_SendCommand(Lcd_FunctionSet);
        // wait 1msec
        _delay_ms(1);
        // DisplayOnOFF
        LCD_SendCommand(Lcd_DisplayOnOFF);
        // wait 1msec
        _delay_ms(1);
        // Clear
        LCD_SendCommand(Lcd_ClearScreen);
        // wait 2msec
        _delay_ms(2);
        //EntryMode
        LCD_SendCommand(Lcd_EntryMode);
        // wait 1msec
        _delay_ms(1);
    #elif LCD_TypeMode==Lcd_4bitMode
        /4BitModeInit
    #endif /* LCD_TypeMode*/
    
}
void LCD_SendCommand(uint8_t Command)
{
    #if LCD_TypeMode==Lcd_8bitMode
        // RS -> Low
        DIO_WritePin(RSGroup,RSPin,DIO_Lowfor1Pin);
        // RW -> Low 
        DIO_WritePin(RWGroup,RWPin,DIO_Lowfor1Pin);
        // DataPin=Command 
        DIO_WriteGroup(DataGroup,Command);
        // E -> High 
        DIO_WritePin(EGroup,EPin,DIO_Highfor1Pin);
        // wait 1msec 
        // E-> Low    
        DIO_WritePin(EGroup,EPin,DIO_Lowfor1Pin);
    #elif LCD_TypeMode==Lcd_4bitMode
        //code
    #endif /* LCD_TypeMode*/
}

void LCD_WriteCharacter(uint8_t Character)
{
    #if LCD_TypeMode==Lcd_8bitMode
        // RS -> High
        DIO_WritePin(RSGroup,RSPin,DIO_Highfor1Pin);
        // RW -> Low 
        DIO_WritePin(RWGroup,RWPin,DIO_Lowfor1Pin);
        // DataPin=Character 
        DIO_WriteGroup(DataGroup,Character);
        // E -> High 
        DIO_WritePin(EGroup,EPin,DIO_Highfor1Pin);
        // wait 1msec 
        // E-> Low    
        DIO_WritePin(EGroup,EPin,DIO_Lowfor1Pin);
    #elif LCD_TypeMode==Lcd_4bitMode
        //code
    #endif /* LCD_TypeMode*/
}

void LCD_WriteString(uint8_t *String)
{
    if(String!=NULL)
    {
        uint8_t Index = 0 ;
        while(String[Index]!=NULLChar)
        {
            LCD_WriteCharacter(String[Index]);
            Index++; 
        }
    }
}

void LCD_MoveTo(uint8_t LineNo,uint8_t DigitNo)
{
    //Select the Location Will be Displayed on Data Display RAM
    uint8_t DDRAM_Address = 0 ;
    switch(LineNo)
    {
        case Lcd_Line1: DDRAM_Address=Lcd_Lin1Address+DigitNo;break;
        case Lcd_Line2: DDRAM_Address=Lcd_Lin2Address+DigitNo;break; /** @bug the Line not Work  */
        default:break;
    }
    LCD_SendCommand(Lcd_SetDDRAMCommand|DDRAM_Address);
    _delay_ms(1);
}


void LCD_WriteNumber(int32_t Number)
{
    uint8_t NumberDigits[10]={0};
    uint8_t Index = 0 ;
    uint8_t Counter = 0 ;
    if(Number==0)
    {
        LCD_WriteCharacter('0');
        return ;
    }
    if(Number<0)
    {
       LCD_WriteCharacter('-');
       Number = Number * -1 ; 
    }
    while(Number!=0)
    {
        // Spareted Numbers 
        NumberDigits[Index] = (Number %10)+'0';
        Number=Number/10;
        Index++;
    }
    for(Counter=Index;Counter>=0;Counter--)
    {
        LCD_WriteCharacter(NumberDigits[Counter-1]);
    }
}

void LCD_StoreSpecialCharacter(uint8_t *SpecialCharacter,uint8_t Location)
{
    if(Location<8)
    {
        uint8_t CGRAM_Address = Location*8;
        LCD_SendCommand(0x40|CGRAM_Address); // Go To CGRAM
        uint8_t Index = 0 ;
        for(Index=0;Index<8;Index++)
        {
            LCD_WriteCharacter(SpecialCharacter[Index]);
        }
        LCD_MoveTo(Lcd_Line1,0);// Back to DDRAM
    }
}
