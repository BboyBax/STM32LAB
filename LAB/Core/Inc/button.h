/*
 * button.h
 *
 *  Created on: Oct 3, 2025
 *      Author: Ha Trong Son
 */

#ifndef INC_BUTTON_H_
#define INC_BUTTON_H_

#include "main.h"

#define NORMAL_STATE SET
#define PRESSED_STATE RESET

extern int button1_flag;
int isButton1Pressed();
void getKeyInput();


#endif /* INC_BUTTON_H_ */
