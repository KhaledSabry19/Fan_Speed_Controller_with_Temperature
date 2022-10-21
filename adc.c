/******************************************************************************
 *
 * Module: ADC
 *
 * File Name: ADC.c
 *
 * Description: Source file for the AVR ADC driver
 *
 * Author: Khaled Sabry
 *
 *******************************************************************************/
#include "adc.h"
#include "common_macros.h" /* To use the macros like SET_BIT */


/*******************************************************************************
 *                      Functions Definitions                                  *
 *******************************************************************************/

void ADC_init(const ADC_ConfigType * Config_Ptr)
{
	ADMUX_REGISTER = 0;
	ADMUX_REGISTER = (ADMUX_REGISTER &~ (0XC0)) | ((Config_Ptr->refernce)<<6);
	ADCSRA_REGISTER = (1<<7);
	ADCSRA_REGISTER = (ADCSRA_REGISTER&~(0X07)) | (Config_Ptr->prescaler);
}

uint16 ADC_readChannel(uint8 channel_num)
{
	channel_num &= 0x07;
	ADMUX_REGISTER &= 0xE0;
	ADMUX_REGISTER = ADMUX_REGISTER | channel_num;
	SET_BIT(ADCSRA_REGISTER,6);
	while(BIT_IS_CLEAR(ADCSRA_REGISTER,4));
	SET_BIT(ADCSRA_REGISTER,4);
	return ADC_REGISTER;
}
