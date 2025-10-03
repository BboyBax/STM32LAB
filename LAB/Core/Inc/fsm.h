/*
 * fsm.h
 *
 *  Created on: Oct 3, 2025
 *      Author: Ha Trong Son
 */

#ifndef INC_FSM_H_
#define INC_FSM_H_

#include "main.h"
#include "software_timer.h"
#include "display7SEG.h"
#include "button.h"

#define INIT 		0
#define RED_GREEN 	1
#define RED_AMBER 	2
#define GREEN_RED 	3
#define AMBER_RED 	4
#define ERROR 		5

void clear_all_led();
void Red_Green();
void Red_Amber();
void Green_Red();
void Amber_Red();
void Error();

void fsm_run();

#endif /* INC_FSM_H_ */
