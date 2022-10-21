/******************************************************************************
 *
 * Module: PWM
 *
 * File Name: pwm_tim0.h
 *
 * Description: Header file for the AVR PWM driver
 *
 * Author: Khaled Sabry
 *
 *******************************************************************************/
#ifndef PWM_TIM0_H_
#define PWM_TIM0_H_

#include "std_types.h"

void PWM_Timer0_Start(uint8 duty_cycle);

#endif /* PWM_TIM0_H_ */
