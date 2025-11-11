/*
 * fsm.c
 *
 *  Created on: Nov 11, 2025
 *      Author: Minh Duy
 */


// INCLUDE LIBRARIES
#include "fsm.h"


// INITIAL
uint8_t buffer[MAX_BUFFER_SIZE];
uint8_t buffer_index = 0;
uint8_t command_flag = 0;
uint8_t command_data = 0;

uint8_t uart_state = 0; // UART_STATE_IDLE -> idle, UART_STATE_WAIT -> wait ACK
uint32_t last_tick = 0;
char str[50];


// FUNCTIONS
// COMMAND PARSER FSM
void command_parser_init(void)
{
	buffer_index = 0;
	command_flag = 0;
};

void command_parser_input(uint8_t input_data)
{
	buffer[buffer_index++] = input_data;
	if(buffer_index >= MAX_BUFFER_SIZE) buffer_index = 0;
};
void command_parser_fsm(void)
{
	// Identify commands with syntax "!---#"

	if(buffer[buffer_index - 1] == '#')
	{
		if(strstr((char*)buffer, "!RST#") )
		{
			command_flag = 1; // command detected
			command_data = CMD_RST; // "!RST#"
		}
		else if(strstr((char*)buffer, "!OK#") )
		{
			command_flag = 1; // command detected
			command_data = CMD_OK; // "!OK#"
		}

		// Reset buffer
		buffer_index = 0;
		memset(buffer, 0, MAX_BUFFER_SIZE);
	}
};

// UART COMMUNICATION FSM
void uart_communication_init(void)
{
	uart_state = 0;
	last_tick = HAL_GetTick();
};
void uart_communication_fsm(void)
{
	uint32_t ADC_value = 0;

	switch(uart_state)
	{
	case 0: // Idle
		if(command_flag && command_data == CMD_RST)
		{
			// Read ADC value
			ADC_value = HAL_ADC_GetValue(&hadc1);

			// Display ADC value on terminal
			sprintf(str, "!ADC=%lu#\r\n", ADC_value);
			HAL_UART_Transmit(&huart2, (uint8_t*)str, strlen(str), 1000);

			// Reset UART state
			uart_state = UART_STATE_WAIT;

			// Get tick to check timeout
			last_tick = HAL_GetTick();

			// Reset command flag
			command_flag = 0;
		}
		break;

	case 1: // Wait ACK
		if(command_flag && command_data == CMD_OK)
		{
			// Reset UART state
			uart_state = UART_STATE_IDLE;

			// Reset command flag
			command_flag = 0;
		}
		if(HAL_GetTick() - last_tick >= 3000)
		{
			// Resend ADC value
			HAL_UART_Transmit(&huart2, (uint8_t*)str, strlen(str), 1000);

			// Get tick to check timeout
			last_tick = HAL_GetTick();
		}
		break;

	default:
		uart_state = UART_STATE_WAIT;
		break;
	}
};
