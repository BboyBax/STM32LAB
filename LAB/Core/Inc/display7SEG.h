/*
 * display7SEG.h
 *
 *  Created on: Oct 3, 2025
 *      Author: Ha Trong Son
 */

#ifndef INC_DISPLAY7SEG_H_
#define INC_DISPLAY7SEG_H_

#include "main.h"
#include "button.h"

#define MAX_LED 4

extern int index_led;

void clear7SEG();
void display7SEG(int number);
void update7SEG(int counter1, int counter2, int counter3, int counter4);
void displayLED();

#endif /* INC_DISPLAY7SEG_H_ */
