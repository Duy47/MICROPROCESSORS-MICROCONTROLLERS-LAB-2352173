/*
 * scheduler.h
 *
 *  Created on: Oct 24, 2025
 *      Author: Minh Duy
 */

#ifndef INC_SCHEDULER_H_
#define INC_SCHEDULER_H_

#include <stdint.h>


// TASK DATA STRUCTURE
typedef struct
{
	// Pointer to the task (must be a ’void (void) ’ function)
	void ( * pTask)(void) ;

	// Delay (ticks) until the function will (next) be run
	uint32_t Delay;

	// Interval (ticks) between subsequent runs.
	uint32_t Period;

	// Incremented (by scheduler) when task is due to execute
	uint8_t RunMe;

	//This is a hint to solve the question below.
	uint32_t TaskID;

} sTask;


// MUST BE ADJUSTED FOR EACH NEW PROJECT
#define SCH_MAX_TASKS	10
#define NO_TASK_ID		 0


// ERROR CODE
#define ERROR_SCH_CANNOT_ADD_TASK		101
#define ERROR_SCH_TOO_MANY_TASKS 		102
#define ERROR_SCH_CANNOT_DELETE_TASK	103

#define RETURN_ERROR 					201
#define RETURN_NORMAL					202


// SCHEDULER FUNCTIONS

uint32_t SCH_Add_Task(void(*pFunction)(), uint32_t DELAY, uint32_t PERIOD);

uint32_t SCH_Delete_Task(uint32_t taskID);

void SCH_Update(void);

void SCH_Dispatch_Tasks(void);

void SCH_Init(void);


#endif /* INC_SCHEDULER_H_ */
