/**
 * @file Atmega32Register.h
 * @author Hesham Ahmed (Hisham4Ahmed@gmail.com)
 * @brief
 * @version 0.1
 * @date 2026-08-20
 *
 * @copyright Copyright (c) 2026
 *
 */
#ifndef _MCAL_ATMEGA32REGISTER_H
#define _MCAL_ATMEGA32REGISTER_H
#include <stdint.h>
/*IO- Memory Map Address*/

#define SREG_Reg *((volatile uint8_t*)0x5F)
/*Stack Pointer */
#define SPH_Reg *((volatile uint8_t*)0x5E)
#define SPL_Reg *((volatile uint8_t*)0x5D)
#define SP_Reg  *((volatile uint16_t*)0x5D)

/*EXTI Phrepheral*/
#define MCUCR_Reg    *((volatile uint8_t*)0x55)
#define MCUCSR_Reg   *((volatile uint8_t*)0x54)
#define GICR_Reg     *((volatile uint8_t*)0x5B)
#define GIFR_Reg     *((volatile uint8_t*)0x5A)


/*ADC*/
#define ADMUX_Reg   *((volatile uint8_t*)0x27)
#define ADCSRA_Reg  *((volatile uint8_t*)0x26)
#define ADCH_Reg    *((volatile uint8_t*)0x25)
#define ADCL_Reg    *((volatile uint8_t*)0x24)
#define ADCData_Reg *((volatile uint16_t*)0x24)
#define SFIOR_Reg   *((volatile uint8_t*)0x50)

/*DIO-GroupA*/
#define DDRA_Reg  *((volatile uint8_t*)0x3A)
#define PORTA_Reg *((volatile uint8_t*)0x3B)
#define PINA_Reg  *((volatile uint8_t*)0x39)


/*DIO-GroupB*/
#define DDRB_Reg  *((volatile uint8_t*)0x37)
#define PORTB_Reg *((volatile uint8_t*)0x38)
#define PINB_Reg  *((volatile uint8_t*)0x36)

/*DIO-GroupC*/
#define DDRC_Reg  *((volatile uint8_t*)0x34)
#define PORTC_Reg *((volatile uint8_t*)0x35)
#define PINC_Reg  *((volatile uint8_t*)0x33)

/*DIO-GroupD*/
#define DDRD_Reg  *((volatile uint8_t*)0x31)
#define PORTD_Reg *((volatile uint8_t*)0x32)
#define PIND_Reg  *((volatile uint8_t*)0x30)



/*Timers*/
#define TIMSK_Reg   *((volatile uint8_t*)0x59)
#define TIFR_Reg    *((volatile uint8_t*)0x58)
#define TCCR0_Reg   *((volatile uint8_t*)0x53)
#define TCNT0_Reg   *((volatile uint8_t*)0x52)
#define OCR0_Reg    *((volatile uint8_t*)0x5C)

#define TCCR2_Reg   *((volatile uint8_t*)0x45)
#define TCNT2_Reg   *((volatile uint8_t*)0x44)
#define OCR2_Reg    *((volatile uint8_t*)0x43)


#define TCCR1A_Reg   *((volatile uint8_t*)0x4F)
#define TCCR1B_Reg   *((volatile uint8_t*)0x4E)

#define TCNT1_Reg    *((volatile uint16_t*)0x4C)
#define TCNT1L_Reg   *((volatile uint8_t*)0x4C)
#define TCNT1H_Reg   *((volatile uint8_t*)0x4D)

#define OCR1A_Reg    *((volatile uint16_t*)0x4A)
#define OCR1AL_Reg   *((volatile uint8_t*)0x4A)
#define OCR1AH_Reg   *((volatile uint8_t*)0x4B)

#define OCR1B_Reg    *((volatile uint16_t*)0x48)
#define OCR1BL_Reg   *((volatile uint8_t*)0x48)
#define OCR1BH_Reg   *((volatile uint8_t*)0x49)

#define ICR1_Reg     *((volatile uint16_t*)0x46)
#define ICR1L_Reg    *((volatile uint8_t*)0x46)
#define ICR1H_Reg    *((volatile uint8_t*)0x47)



#endif /*_MCAL_ATMEGA32REGISTER_H*/
