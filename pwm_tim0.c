/******************************************************************************
 *
 * Module: PWM
 *
 * File Name: pwm_tim0.c
 *
 * Description: Source file for the AVR PWM driver
 *
 * Author: Khaled Sabry
 *
 *******************************************************************************/
#include "pwm_tim0.h"

#include <avr/io.h>
#include "common_macros.h"

void PWM_Timer0_Start(uint8 duty_cycle)
{
	TCNT0 = 0;
	OCR0 = (int)(((float)duty_cycle / 100) * 255);
	DDRB|=(1<<PB3);
	TCCR0 = (1<<WGM00) | (1<<WGM01) | (1<<COM01) | (1<<CS01);
}

