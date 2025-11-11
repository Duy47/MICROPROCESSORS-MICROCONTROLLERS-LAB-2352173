/*
 * fsm.h
 *
 *  Created on: Nov 11, 2025
 *      Author: Minh Duy
 */

#ifndef INC_FSM_H_
#define INC_FSM_H_


// INCLUDE LIBRARIES
#include "stm32f1xx_hal.h"
#include <string.h>
#include <stdio.h>

#define MAX_BUFFER_SIZE 30

#define CMD_RST 00
#define CMD_OK 01

#define UART_STATE_IDLE 10
#define UART_STATE_WAIT 11

// INITIAL
extern UART_HandleTypeDef huart2;
extern ADC_HandleTypeDef hadc1;

extern uint8_t buffer[MAX_BUFFER_SIZE];
extern uint8_t buffer_index;
extern uint8_t command_flag; // 1 -> new command
extern uint8_t command_data; // CMD_RST -> !RST#, CMD_OK = !OK#


// FUNCTIONS
// COMMAND PARSER FSM
void command_parser_init(void);
void command_parser_input(uint8_t input_data);
void command_parser_fsm(void);

// UART COMMUNICATION FSM
void uart_communication_init(void);
void uart_communication_fsm(void);


#endif /* INC_FSM_H_ */
