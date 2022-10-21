/******************************************************************************
 *
 * Module: App Program
 *
 * File Name: main.c
 *
 * Description: Source file for the Fan Controller System Project
 *
 * Author: Khaled Sabry
 *
 *******************************************************************************/
#include "lm35_sensor.h"
#include "dc_motor.h"

int main (void)
{
	LCD_init();
	LCD_moveCursor(0, 3);
	LCD_displayString("Fan is ");
	LCD_moveCursor(1, 3);
	LCD_displayString("Temp = ");

	uint8 g_temp = LM35_getTemperature();

	LCD_moveCursor(1, 9);
	LCD_intgerToString(g_temp);
	LCD_displayString(" C");
    DC_Motor_Init ();

	DcMotor_State g_dcMotorState = ClockWise;
	uint8 g_dcMotorSpeed = 0;

	DC_Motor_Rotate (g_dcMotorState, g_dcMotorSpeed);

	while(1)
		{
			g_temp = LM35_getTemperature();
			LCD_moveCursor(1, 9);
			LCD_displayCharacter(' ');
			LCD_intgerToString(g_temp);
			LCD_displayString(" C ");

			if(g_temp < 30)
			{
				LCD_moveCursor(0, 10);
				LCD_displayString(" OFF ");
				g_dcMotorState = Stop;
				g_dcMotorSpeed = 0;
				DC_Motor_Rotate(g_dcMotorState, g_dcMotorSpeed);
			}
			else if(g_temp >= 120)
			{
				LCD_moveCursor(0, 10);
				LCD_displayString(" ON ");
				g_dcMotorState = ClockWise;
				g_dcMotorSpeed = 100;
				DC_Motor_Rotate(g_dcMotorState, g_dcMotorSpeed);
			}
			else if(g_temp >= 90)
			{
				LCD_moveCursor(0, 10);
				LCD_displayString(" ON ");
				g_dcMotorState = ClockWise;
				g_dcMotorSpeed = 75;
				DC_Motor_Rotate(g_dcMotorState, g_dcMotorSpeed);
			}
			else if(g_temp >= 60)
			{
				LCD_moveCursor(0, 10);
				LCD_displayString(" ON ");
				g_dcMotorState = ClockWise;
				g_dcMotorSpeed = 50;
				DC_Motor_Rotate(g_dcMotorState, g_dcMotorSpeed);
			}
			else if(g_temp >= 30)
			{
				LCD_moveCursor(0, 10);
				LCD_displayString(" ON ");
				g_dcMotorState = ClockWise;
				g_dcMotorSpeed = 25;
				DC_Motor_Rotate(g_dcMotorState, g_dcMotorSpeed);
			}
		}
		return 0;
	}

