/******************************************************************************
 *
 * Module: ADC
 *
 * File Name: adc.h
 *
 * Description: Header file for the AVR ADC driver
 *
 * Author: Khaled Sabry
 *
 *******************************************************************************/
#ifndef ADC_H_
#define ADC_H_

#include "std_types.h"

#define ADMUX_REGISTER  *((volatile uint8*)0x27)

#define ADCSRA_REGISTER  *((volatile uint8*)0x26)

#define SFIOR_REGISTER  *((volatile uint8*)0x50)

#define ADCH_REGISTER  *((volatile uint8*)0x25)

#define ADCL_REGISTER  *((volatile uint8*)0x24)

#define ADC_REGISTER  *((volatile uint16*)0x24)

#define ADC_MAXIMUM_VALUE    1023
#define ADC_REF_VOLT_VALUE   2.56

typedef enum
{
	AREF, AVCC, INTERNAL_2_56 = 3
}ADC_ReferenceVoltage;

typedef enum {
	F_CUP_2 = 1, F_CUP_4, F_CUP_8, F_CUP_16, F_CUP_32, F_CUP_64, F_CPU_128
}ADC_Prescaler;

typedef struct{
	ADC_ReferenceVoltage refernce;
	ADC_Prescaler prescaler;
}ADC_ConfigType;

void ADC_init(const ADC_ConfigType * Config_Ptr);

uint16 ADC_readChannel(uint8 channel_num);

#endif /* ADC_H_ */
