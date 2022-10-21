 /******************************************************************************
 *
 * Module: GPIO
 *
 * File Name: gpio.c
 *
 * Description: Source file for the AVR GPIO driver
 *
 * Author: Khaled Sabry
 *
 *******************************************************************************/

#include "gpio.h"
#include "common_macros.h"


void GPIO_setupPinDirection(uint8 port_num, uint8 pin_num, GPIO_PinDirectionType direction)
{

	if((pin_num >= NUM_OF_PINS_PER_PORT) || (port_num >= NUM_OF_PORTS))
	{
		/* Do Nothing */
	}
	else
	{

		switch(port_num)
		{
		case PORTA_ID:
			if(direction == PIN_OUTPUT)
			{
				SET_BIT(DDRA_REGISTER,pin_num);
			}
			else
			{
				CLEAR_BIT(DDRA_REGISTER,pin_num);
			}
			break;
		case PORTB_ID:
			if(direction == PIN_OUTPUT)
			{
				SET_BIT(DDRB_REGISTER,pin_num);
			}
			else
			{
				CLEAR_BIT(DDRB_REGISTER,pin_num);
			}
			break;
		case PORTC_ID:
			if(direction == PIN_OUTPUT)
			{
				SET_BIT(DDRC_REGISTER,pin_num);
			}
			else
			{
				CLEAR_BIT(DDRC_REGISTER,pin_num);
			}
			break;
		case PORTD_ID:
			if(direction == PIN_OUTPUT)
			{
				SET_BIT(DDRD_REGISTER,pin_num);
			}
			else
			{
				CLEAR_BIT(DDRD_REGISTER,pin_num);
			}
			break;
		}
	}
}

void GPIO_writePin(uint8 port_num, uint8 pin_num, uint8 value)
{

	if((pin_num >= NUM_OF_PINS_PER_PORT) || (port_num >= NUM_OF_PORTS))
	{
		/* Do Nothing */
	}
	else
	{

		switch(port_num)
		{
		case PORTA_ID:
			if(value == LOGIC_HIGH)
			{
				SET_BIT(PORTA_REGISTER,pin_num);
			}
			else
			{
				CLEAR_BIT(PORTA_REGISTER,pin_num);
			}
			break;
		case PORTB_ID:
			if(value == LOGIC_HIGH)
			{
				SET_BIT(PORTB_REGISTER,pin_num);
			}
			else
			{
				CLEAR_BIT(PORTB_REGISTER,pin_num);
			}
			break;
		case PORTC_ID:
			if(value == LOGIC_HIGH)
			{
				SET_BIT(PORTC_REGISTER,pin_num);
			}
			else
			{
				CLEAR_BIT(PORTC_REGISTER,pin_num);
			}
			break;
		case PORTD_ID:
			if(value == LOGIC_HIGH)
			{
				SET_BIT(PORTD_REGISTER,pin_num);
			}
			else
			{
				CLEAR_BIT(PORTD_REGISTER,pin_num);
			}
			break;
		}
	}
}


uint8 GPIO_readPin(uint8 port_num, uint8 pin_num)
{
	uint8 pin_value = LOGIC_LOW;

	if((pin_num >= NUM_OF_PINS_PER_PORT) || (port_num >= NUM_OF_PORTS))
	{
		/* Do Nothing */
	}
	else
	{

		switch(port_num)
		{
		case PORTA_ID:
			if(BIT_IS_SET(PINA_REGISTER,pin_num))
			{
				pin_value = LOGIC_HIGH;
			}
			else
			{
				pin_value = LOGIC_LOW;
			}
			break;
		case PORTB_ID:
			if(BIT_IS_SET(PINB_REGISTER,pin_num))
			{
				pin_value = LOGIC_HIGH;
			}
			else
			{
				pin_value = LOGIC_LOW;
			}
			break;
		case PORTC_ID:
			if(BIT_IS_SET(PINC_REGISTER,pin_num))
			{
				pin_value = LOGIC_HIGH;
			}
			else
			{
				pin_value = LOGIC_LOW;
			}
			break;
		case PORTD_ID:
			if(BIT_IS_SET(PIND_REGISTER,pin_num))
			{
				pin_value = LOGIC_HIGH;
			}
			else
			{
				pin_value = LOGIC_LOW;
			}
			break;
		}
	}

	return pin_value;
}


void GPIO_setupPortDirection(uint8 port_num, GPIO_PortDirectionType direction)
{

	if(port_num >= NUM_OF_PORTS)
	{
		/* Do Nothing */
	}
	else
	{

		switch(port_num)
		{
		case PORTA_ID:
			DDRA_REGISTER = direction;
			break;
		case PORTB_ID:
			DDRB_REGISTER = direction;
			break;
		case PORTC_ID:
			DDRC_REGISTER = direction;
			break;
		case PORTD_ID:
			DDRD_REGISTER = direction;
			break;
		}
	}
}


void GPIO_writePort(uint8 port_num, uint8 value)
{
	if(port_num >= NUM_OF_PORTS)
	{
		/* Do Nothing */
	}
	else
	{

		switch(port_num)
		{
		case PORTA_ID:
			PORTA_REGISTER = value;
			break;
		case PORTB_ID:
			PORTB_REGISTER = value;
			break;
		case PORTC_ID:
			PORTC_REGISTER = value;
			break;
		case PORTD_ID:
			PORTD_REGISTER = value;
			break;
		}
	}
}


uint8 GPIO_readPort(uint8 port_num)
{
	uint8 value = LOGIC_LOW;

	if(port_num >= NUM_OF_PORTS)
	{
		/* Do Nothing */
	}
	else
	{

		switch(port_num)
		{
		case PORTA_ID:
			value = PINA_REGISTER;
			break;
		case PORTB_ID:
			value = PINB_REGISTER;
			break;
		case PORTC_ID:
			value = PINC_REGISTER;
			break;
		case PORTD_ID:
			value = PIND_REGISTER;
			break;
		}
	}

	return value;
}
