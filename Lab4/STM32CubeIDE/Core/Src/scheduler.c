/*
 * scheduler.c
 *
 *  Created on: Oct 24, 2025
 *      Author: Minh Duy
 */

#include "main.h"
#include "scheduler.h"

# define TICK 10

// INITIAL DECLARATION
sTask SCH_tasks_G[SCH_MAX_TASKS];

uint32_t Last_error_code_G = 0;
uint32_t Error_code_G = 0;



// SCHEDULER FUNCTIONS

uint32_t SCH_Add_Task(void(*pFunction)(), uint32_t DELAY, uint32_t PERIOD)
{
	// Check for invalid input
	if(pFunction == 0 || DELAY < 0 || PERIOD < 0)
	{
		Error_code_G = ERROR_SCH_CANNOT_ADD_TASK;
		return Error_code_G;
	}

	 uint32_t Index = 0;
	 // First find a gap in the array (if there is one)
	 while ((SCH_tasks_G[Index].pTask != 0) && (Index < SCH_MAX_TASKS))
	 {
		 Index++;
	 }

	 // Have we reached the end of the list?
	 if (Index == SCH_MAX_TASKS)
	 {
		 // Task list is full
		 // Set the global error variable
		 Error_code_G = ERROR_SCH_TOO_MANY_TASKS;
		 // Also return an error code
		 return SCH_MAX_TASKS;
	 }

	 // If we’re here, there is a space in the task array
	 SCH_tasks_G[Index].pTask = pFunction;
	 SCH_tasks_G[Index].Delay = DELAY;
	 SCH_tasks_G[Index].Period = PERIOD;
	 SCH_tasks_G[Index].RunMe = 0;

	 return Index;
};

uint32_t SCH_Delete_Task(const uint32_t TASK_ID)
{
	uint32_t Return_Code;

	if(SCH_tasks_G[TASK_ID].pTask == 0)
	 {
		 // No task at this location ...
		 //
		 // Set the global error variable
		 Error_code_G = ERROR_SCH_CANNOT_DELETE_TASK;

		 // ... also return an error code
		 Return_Code = RETURN_ERROR;
	 }
	 else
	 {
		 Return_Code = RETURN_NORMAL;
	 }

	 SCH_tasks_G[TASK_ID].pTask = NULL;
	 SCH_tasks_G[TASK_ID]. Delay = 0;
	 SCH_tasks_G[TASK_ID]. Period = 0;
	 SCH_tasks_G[TASK_ID].RunMe = 0;

	 return Return_Code; // return status
};

void SCH_Update(void)
{
	 uint32_t Index;
	 //NOTE: calculations are in *TICKS* (not milliseconds)
	 for (Index = 0; Index <SCH_MAX_TASKS; Index++)
	 {
		 // Check if there is a task at this location
		 if (SCH_tasks_G[Index].pTask)
		 {
			 if (SCH_tasks_G[Index].Delay == 0)
			 {
				 // The task is due to run
				 // Inc. the ’RunMe’ flag
				 SCH_tasks_G[Index].RunMe = 1;
				 if (SCH_tasks_G[Index].Period > 0)
				 {
					 // Schedule periodic tasks to run again
					 SCH_tasks_G[Index].Delay = SCH_tasks_G[Index].Period;
				 }
			 }
			 else
			 {
				 // Not yet ready to run: just decrement the delay
				 SCH_tasks_G[Index].Delay -= 1;
			 };
		 };
	 };
};

void SCH_Dispatch_Tasks(void)
{
	uint32_t Index;

	// Dispatches (runs) the next task (if one is ready)
	for (Index = 0; Index < SCH_MAX_TASKS; Index++)
	{
		if (SCH_tasks_G[Index].RunMe > 0)
		{
			(*SCH_tasks_G[Index].pTask)(); // Run the task
			SCH_tasks_G[Index].RunMe = 0; // Reset / reduceRunMe flag

			// Periodic tasks will automatically run again
			// − if this is a ’one shot’ task, remove it from the array
			if (SCH_tasks_G[Index].Period == 0)
			{
				SCH_Delete_Task(Index);
			}
		}
	}
};

void SCH_Init(void)
{
	for (int Index = 0; Index < SCH_MAX_TASKS; ++Index)
	{
		SCH_Delete_Task(Index);
	}

	Error_code_G = 0;
};
