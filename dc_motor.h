/******************************************************************************
 *
 * Module: DC-MOTOR
 *
 * File Name: dc-motor.h
 *
 * Description: Header file for the DC-MOTOR driver
 *
 * Author: Khaled Sabry
 *
 *******************************************************************************/
#ifndef DC_MOTOR_H_
#define DC_MOTOR_H_

#include "std_types.h"

#define	DCMOTOR_M1_PORT_ID 		 PORTB_ID
#define	DCMOTOR_M1_PIN1_ID		 PIN0_ID
#define	DCMOTOR_M1_PIN2_ID		 PIN1_ID

typedef enum
{
	ClockWise, AntiClockWise, Stop
} DcMotor_State;


void DC_Motor_Init(void);


void DC_Motor_Rotate(DcMotor_State state,uint8 speed);

#endif /* DC_MOTOR_H_ */
