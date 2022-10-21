/******************************************************************************
 *
 * Module: DC-MOTOR
 *
 * File Name: dc-motor.c
 *
 * Description: Source file for the DC-MOTOR driver
 *
 * Author: Khaled Sabry
 *
 *******************************************************************************/
#include "dc_motor.h"
#include "gpio.h"
#include "pwm_tim0.h"


static uint8 g_currentSpeed = 1;


void DC_Motor_Init(void)
{
	GPIO_setupPinDirection(DCMOTOR_M1_PORT_ID, DCMOTOR_M1_PIN1_ID, PIN_OUTPUT);
	GPIO_setupPinDirection(DCMOTOR_M1_PORT_ID, DCMOTOR_M1_PIN2_ID, PIN_OUTPUT);
	GPIO_writePin(DCMOTOR_M1_PORT_ID, DCMOTOR_M1_PIN1_ID, LOGIC_LOW);
	GPIO_writePin(DCMOTOR_M1_PORT_ID, DCMOTOR_M1_PIN2_ID, LOGIC_LOW);
}


void DC_Motor_Rotate(DcMotor_State state,uint8 speed)
{
	switch(state)
	{
	case ClockWise:
		GPIO_writePin(DCMOTOR_M1_PORT_ID, DCMOTOR_M1_PIN1_ID, LOGIC_LOW);
		GPIO_writePin(DCMOTOR_M1_PORT_ID, DCMOTOR_M1_PIN2_ID, LOGIC_HIGH);
		break;
	case AntiClockWise:
		GPIO_writePin(DCMOTOR_M1_PORT_ID, DCMOTOR_M1_PIN1_ID, LOGIC_HIGH);
		GPIO_writePin(DCMOTOR_M1_PORT_ID, DCMOTOR_M1_PIN2_ID, LOGIC_LOW);
		break;
	case Stop:
		GPIO_writePin(DCMOTOR_M1_PORT_ID, DCMOTOR_M1_PIN1_ID, LOGIC_LOW);
		GPIO_writePin(DCMOTOR_M1_PORT_ID, DCMOTOR_M1_PIN2_ID, LOGIC_LOW);
		break;
	}
	if(g_currentSpeed != speed)
	{
		PWM_Timer0_Start(speed);
		g_currentSpeed = speed;
	}
}
