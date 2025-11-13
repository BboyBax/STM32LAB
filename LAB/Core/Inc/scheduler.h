/*
 * scheduler.h
 *
 *  Created on: Nov 13, 2025
 *      Author: Ha Trong Son
 */

#ifndef INC_SCHEDULER_H_
#define INC_SCHEDULER_H_

#include "stdint.h"

#define SCH_MAX_TASKS 					10
#define	NO_TASK_ID						0
#define NORMAL 							0
#define ERROR_SCH_TOO_MANY_TASKS		1
#define ERROR_SCH_CANNOT_DELETE_TASK	2
#define RETURN_NORMAL					0
#define RETURN_ERROR 					1

extern int Error_code_G;

typedef struct {
	void (* pTask)(void);
	uint32_t Delay;
	uint32_t Period;
	uint8_t RunMe;
	uint32_t TaskID;
} sTask;

void SCH_Init(void);
void SCH_Update(void);
uint32_t SCH_Add_Task(void (*p_function)(), uint32_t DELAY, uint32_t PERIOD);
void SCH_Dispatch_Tasks(void);
uint8_t SCH_Delete_Task(uint32_t TASK_ID);



#endif /* INC_SCHEDULER_H_ */

