/*
 * scheduler.c
 *
 *  Created on: Nov 13, 2025
 *      Author: Ha Trong Son
 */

#include "scheduler.h"
int Error_code_G = NORMAL;

sTask SCH_tasks_G[SCH_MAX_TASKS];
static uint32_t newTaskID = 0;
void shift_right(sTask *array, unsigned char index){
	unsigned char i;
	for (i = SCH_MAX_TASKS - 1; i > index; i--){
		array[i] = array[i-1];
	}
	return;
}

void shift_left(sTask *array){
	unsigned char i;
	for (i = 1; i < SCH_MAX_TASKS; i++){
		array[i - 1] = array[i];
	}
	return;
}

int count_task(sTask *array){
	int count = 0;
	for (unsigned char i = 0; i < SCH_MAX_TASKS; i++){
		if (SCH_tasks_G[i].pTask != 0){
			count++;
		} else {
			break;
		}
	}
	return count;
}

uint32_t Get_New_Task_ID(void){
	newTaskID++;
	if(newTaskID == NO_TASK_ID){
		newTaskID++;
	}
	return newTaskID;
}

void SCH_Init(void){
	unsigned char i;
	for (i = 0; i < SCH_MAX_TASKS; i++){
	        SCH_tasks_G[i].pTask = 0;
	        SCH_tasks_G[i].Delay = 0;
	        SCH_tasks_G[i].Period = 0;
	        SCH_tasks_G[i].RunMe = 0;
	        SCH_tasks_G[i].TaskID = SCH_MAX_TASKS;
	    }
	Error_code_G = NORMAL;
}

void SCH_Update(void){
	if (SCH_tasks_G[0].pTask && SCH_tasks_G[0].RunMe == 0) {
		if(SCH_tasks_G[0].Delay > 0){
			SCH_tasks_G[0].Delay = SCH_tasks_G[0].Delay - 1;
		}
		if (SCH_tasks_G[0].Delay == 0) {
			SCH_tasks_G[0].RunMe = 1;
		}
	}
}

//uint32_t SCH_Add_Task(void (*p_function)(), uint32_t DELAY, uint32_t PERIOD) {
//    uint32_t sum_delay = 0;
//    unsigned char index = 0;
//
//    while ((index < SCH_MAX_TASKS) && (SCH_tasks_G[index].pTask != 0)) {
//        index++;
//    }
//
//    if (index == SCH_MAX_TASKS) {
//        Error_code_G = ERROR_SCH_TOO_MANY_TASKS;
//        return SCH_MAX_TASKS;
//    }
//
//    for (index = 0; index < SCH_MAX_TASKS; index++) {
//        uint32_t temp_delay = SCH_tasks_G[index].Delay;
//        sum_delay += temp_delay;
//        if (DELAY < temp_delay) {
//            SCH_tasks_G[index].Delay -= DELAY;
//            shift_right(SCH_tasks_G, index);
//            SCH_tasks_G[index].pTask = p_function;
//            SCH_tasks_G[index].Delay = DELAY;
//            SCH_tasks_G[index].Period = PERIOD;
//            SCH_tasks_G[index].RunMe = (DELAY == 0) ? 1 : 0;
//            SCH_tasks_G[index].TaskID = index;
//            return SCH_tasks_G[index].TaskID;
//        }
//        else {
//            DELAY -= temp_delay;
//            if (SCH_tasks_G[index].pTask == 0) {
//                SCH_tasks_G[index].pTask = p_function;
//                SCH_tasks_G[index].Delay = DELAY;
//                SCH_tasks_G[index].Period = PERIOD;
//                SCH_tasks_G[index].RunMe = (DELAY == 0) ? 1 : 0;
//                SCH_tasks_G[index].TaskID = index;
//                return SCH_tasks_G[index].TaskID;
//            }
//        }
//    }
//    return SCH_MAX_TASKS;
//}

uint32_t SCH_Add_Task(void (* pFunction)(), uint32_t DELAY, uint32_t PERIOD){
	uint8_t newTaskIndex = 0;
	uint32_t sumDelay = 0;
	uint32_t newDelay = 0;

	for(newTaskIndex = 0; newTaskIndex < SCH_MAX_TASKS; newTaskIndex ++){
		sumDelay = sumDelay + SCH_tasks_G[newTaskIndex].Delay;
		if(sumDelay > DELAY){
			newDelay = DELAY - (sumDelay - SCH_tasks_G[newTaskIndex].Delay);
			SCH_tasks_G[newTaskIndex].Delay = sumDelay - DELAY;
			for(uint8_t i = SCH_MAX_TASKS - 1; i > newTaskIndex; i --){
//				if(SCH_tasks_G[i - 1].pTask != 0)
				{
					SCH_tasks_G[i].pTask = SCH_tasks_G[i - 1].pTask;
					SCH_tasks_G[i].Period = SCH_tasks_G[i - 1].Period;
					SCH_tasks_G[i].Delay = SCH_tasks_G[i - 1].Delay;
//					SCH_tasks_G[i].RunMe = SCH_tasks_G[i - 1].RunMe;
					SCH_tasks_G[i].TaskID = SCH_tasks_G[i - 1].TaskID;
				}
			}
			SCH_tasks_G[newTaskIndex].pTask = pFunction;
			SCH_tasks_G[newTaskIndex].Delay = newDelay;
			SCH_tasks_G[newTaskIndex].Period = PERIOD;
			if(SCH_tasks_G[newTaskIndex].Delay == 0){
				SCH_tasks_G[newTaskIndex].RunMe = 1;
			} else {
				SCH_tasks_G[newTaskIndex].RunMe = 0;
			}
			SCH_tasks_G[newTaskIndex].TaskID = Get_New_Task_ID();
			return SCH_tasks_G[newTaskIndex].TaskID;
		} else {
			if(SCH_tasks_G[newTaskIndex].pTask == 0x0000){
				SCH_tasks_G[newTaskIndex].pTask = pFunction;
				SCH_tasks_G[newTaskIndex].Delay = DELAY - sumDelay;
				SCH_tasks_G[newTaskIndex].Period = PERIOD;
				if(SCH_tasks_G[newTaskIndex].Delay == 0){
					SCH_tasks_G[newTaskIndex].RunMe = 1;
				} else {
					SCH_tasks_G[newTaskIndex].RunMe = 0;
				}
				SCH_tasks_G[newTaskIndex].TaskID = Get_New_Task_ID();
				return SCH_tasks_G[newTaskIndex].TaskID;
			}
		}
	}
	return SCH_tasks_G[newTaskIndex].TaskID;
}

void SCH_Dispatch_Tasks(void){
	if(SCH_tasks_G[0].RunMe > 0) {
		(*SCH_tasks_G[0].pTask)();
		SCH_tasks_G[0].RunMe = 0;
		sTask temtask = SCH_tasks_G[0];
		SCH_Delete_Task(temtask.TaskID);
		if (temtask.Period != 0) {
			SCH_Add_Task(temtask.pTask, temtask.Period, temtask.Period);
		}
	}
}

uint8_t SCH_Delete_Task(uint32_t TASK_ID){
	unsigned char return_code;
	if (SCH_tasks_G[TASK_ID].pTask == 0){
		Error_code_G = ERROR_SCH_CANNOT_DELETE_TASK;
		return_code = RETURN_ERROR;
	} else {
		return_code = RETURN_NORMAL;
	}
	shift_left(SCH_tasks_G);
	SCH_tasks_G[SCH_MAX_TASKS - 1].pTask = 0x0000;
	SCH_tasks_G[SCH_MAX_TASKS - 1].Delay = 0;
	SCH_tasks_G[SCH_MAX_TASKS - 1].Period = 0;
	SCH_tasks_G[SCH_MAX_TASKS - 1].RunMe = 0;
	return return_code;
}



//void SCH_Update(void){
//	unsigned char index;
//
//	for (index = 0; index < SCH_MAX_TASKS; index++){
//		if (SCH_tasks_G[index].pTask){
//			if (SCH_tasks_G[index].Delay == 0){
//				SCH_tasks_G[index].RunMe += 1;
//				if (SCH_tasks_G[index].Period){
//					SCH_tasks_G[index].Delay = SCH_tasks_G[index].Period;
//				}
//			} else {
//				SCH_tasks_G[index].Delay -= 1;
//			}
//		}
//	}
//}
//
//uint32_t SCH_Add_Task(void (*p_function)(), uint32_t DELAY, uint32_t PERIOD){
//	unsigned char index = 0;
//
//	while ((index < SCH_MAX_TASKS) && (SCH_tasks_G[index].pTask != 0)){
//		index++;
//	}
//	if (index == SCH_MAX_TASKS){
//		Error_code_G = ERROR_SCH_TOO_MANY_TASKS;
//		return SCH_MAX_TASKS;
//	}
//	 SCH_tasks_G[index].pTask = p_function;
//	 SCH_tasks_G[index].Delay = DELAY;
//	 SCH_tasks_G[index].Period = PERIOD;
//	 SCH_tasks_G[index].RunMe = 0;
//
//	 return index;
//}
//
//void SCH_Dispatch_Tasks(void){
//	unsigned char index;
//
//	for (index = 0; index < SCH_MAX_TASKS; index++){
//		if (SCH_tasks_G[index].RunMe > 0){
//			(*SCH_tasks_G[index].pTask)();
//			SCH_tasks_G[index].RunMe -= 1;
//			if (SCH_tasks_G[index].Period == 0){
//				SCH_Delete_Task(index);
//			}
//		}
//	}
////	// Report system status
////	SCH_Report_Status();
////	// The scheduler enters idle mode at this point
////	SCH_Go_To_Sleep();
//}
//
//uint8_t SCH_Delete_Task(uint32_t TASK_ID){
//	unsigned char return_code;
//	if (SCH_tasks_G[TASK_ID].pTask == 0){
//		Error_code_G = ERROR_SCH_CANNOT_DELETE_TASK;
//		return_code = RETURN_ERROR;
//	} else {
//		return_code = RETURN_NORMAL;
//	}
//	 SCH_tasks_G[TASK_ID].pTask = 0x0000;
//	 SCH_tasks_G[TASK_ID]. Delay = 0;
//	 SCH_tasks_G[TASK_ID]. Period = 0;
//	 SCH_tasks_G[TASK_ID].RunMe = 0;
//	 return return_code;
//}
