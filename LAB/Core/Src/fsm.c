/*
 * fsm.c
 *
 *  Created on: Oct 3, 2025
 *      Author: Ha Trong Son
 */

#include "fsm.h"


int temp_error = 0;

void clear_all_led(){
	HAL_GPIO_WritePin(RED1_GPIO_Port, RED1_Pin, SET);
	HAL_GPIO_WritePin(RED2_GPIO_Port, RED2_Pin, SET);
	HAL_GPIO_WritePin(GREEN1_GPIO_Port, GREEN1_Pin , SET);
	HAL_GPIO_WritePin(GREEN2_GPIO_Port, GREEN2_Pin , SET);
	HAL_GPIO_WritePin(AMBER1_GPIO_Port, AMBER1_Pin, SET);
	HAL_GPIO_WritePin(AMBER2_GPIO_Port, AMBER2_Pin, SET);
	return;
}

void Red_Green(){
	HAL_GPIO_WritePin(RED2_GPIO_Port, RED2_Pin, SET);
	HAL_GPIO_WritePin(GREEN1_GPIO_Port, GREEN1_Pin , SET);
	HAL_GPIO_WritePin(AMBER1_GPIO_Port, AMBER1_Pin, SET);
	HAL_GPIO_WritePin(AMBER2_GPIO_Port, AMBER2_Pin, SET);

	HAL_GPIO_WritePin(RED1_GPIO_Port, RED1_Pin, RESET);
	HAL_GPIO_WritePin(GREEN2_GPIO_Port, GREEN2_Pin , RESET);
}
void Red_Amber() {
	HAL_GPIO_WritePin(RED2_GPIO_Port, RED2_Pin, SET);
	HAL_GPIO_WritePin(GREEN1_GPIO_Port, GREEN1_Pin , SET);
	HAL_GPIO_WritePin(GREEN2_GPIO_Port, GREEN2_Pin , SET);
	HAL_GPIO_WritePin(AMBER1_GPIO_Port, AMBER1_Pin, SET);

	HAL_GPIO_WritePin(RED1_GPIO_Port, RED1_Pin, RESET);
	HAL_GPIO_WritePin(AMBER2_GPIO_Port, AMBER2_Pin, RESET);


}
void Green_Red() {
	HAL_GPIO_WritePin(RED1_GPIO_Port, RED1_Pin, SET);
	HAL_GPIO_WritePin(GREEN2_GPIO_Port, GREEN2_Pin , SET);
	HAL_GPIO_WritePin(AMBER1_GPIO_Port, AMBER1_Pin, SET);
	HAL_GPIO_WritePin(AMBER2_GPIO_Port, AMBER2_Pin, SET);

	HAL_GPIO_WritePin(GREEN1_GPIO_Port, GREEN1_Pin , RESET);
	HAL_GPIO_WritePin(RED2_GPIO_Port, RED2_Pin, RESET);
}
void Amber_Red() {
	HAL_GPIO_WritePin(RED1_GPIO_Port, RED1_Pin, SET);
	HAL_GPIO_WritePin(GREEN1_GPIO_Port, GREEN1_Pin , SET);
	HAL_GPIO_WritePin(GREEN2_GPIO_Port, GREEN2_Pin , SET);
	HAL_GPIO_WritePin(AMBER2_GPIO_Port, AMBER2_Pin, SET);

	HAL_GPIO_WritePin(AMBER1_GPIO_Port, AMBER1_Pin, RESET);
	HAL_GPIO_WritePin(RED2_GPIO_Port, RED2_Pin, RESET);
}

void Error() {
	HAL_GPIO_WritePin(GREEN1_GPIO_Port, GREEN1_Pin , SET);
	HAL_GPIO_WritePin(GREEN2_GPIO_Port, GREEN2_Pin , SET);
	HAL_GPIO_WritePin(AMBER2_GPIO_Port, AMBER2_Pin, SET);
	HAL_GPIO_WritePin(AMBER1_GPIO_Port, AMBER1_Pin, SET);
	switch (temp_error) {
	case 0:
		HAL_GPIO_WritePin(RED1_GPIO_Port, RED1_Pin, RESET);
		HAL_GPIO_WritePin(RED2_GPIO_Port, RED2_Pin, RESET);
		temp_error = 1;
		break;
	case 1:
		HAL_GPIO_WritePin(RED1_GPIO_Port, RED1_Pin, SET);
		HAL_GPIO_WritePin(RED2_GPIO_Port, RED2_Pin, SET);
		temp_error = 0;
		break;
	default:
		break;
	}
}

int state = 0;
int counter1 = 0;
int counter2 = 0;
void fsm_run(){
	if (isTimerExpired(19) == 1){
		setTimer(19, 50);
		HAL_GPIO_TogglePin(LED_BLINK_GPIO_Port, LED_BLINK_Pin);
	}
	switch (state){
	case INIT:
		button1_flag = 0;
		clear_all_led();
		clear7SEG();
		if (isTimerExpired(0) == 1){
			state = RED_GREEN;
			counter1 = 7;
			counter2 = 5;
			setTimer(0, 500);
		}
		if (isTimerExpired(1) == 1){
			update7SEG(counter1, counter2);
			setTimer(1, 100);
		}
		if (isTimerExpired(18) == 1){
			displayLED();
			setTimer(18, 10);
		}
		break;
	case RED_GREEN:
		Red_Green();
		if (isTimerExpired(18) == 1){
			displayLED();
			setTimer(18, 10);
		}
		if (isTimerExpired(1) == 1){
			counter1--;
			counter2--;
			update7SEG(counter1, counter2);
			setTimer(1, 100);
		}
		if (isTimerExpired(0) == 1){
			state = RED_AMBER;
			counter1 = 2;
			counter2 = 2;
			setTimer(0, 200);
		}
		break;
	case RED_AMBER:
		Red_Amber();
		if (isTimerExpired(18) == 1){
			displayLED();
			setTimer(18, 20);
		}
		if (isTimerExpired(1) == 1){
			counter1--;
			counter2--;
			update7SEG(counter1, counter2);
			setTimer(1, 100);
		}
		if (isTimerExpired(0) == 1){
			state = GREEN_RED;
			counter1 = 5;
			counter2 = 7;
			setTimer(0, 500);
			button1_flag = 0;
		}
		break;
	case GREEN_RED:
		if (isButton1Pressed() == 1){
			state = ERROR;
			button1_flag = 0;
			setTimer(3, 50);
			break;
		}
		Green_Red();

		if (isTimerExpired(18) == 1){
			displayLED();
			setTimer(18, 10);
		}
		if (isTimerExpired(1) == 1){
			counter1--;
			counter2--;
			update7SEG(counter1, counter2);
			setTimer(1, 100);
		}
		if (isTimerExpired(0) == 1){
			state = AMBER_RED;
			counter1 = 2;
			counter2 = 2;
			setTimer(0, 200);
		}
		break;
	case AMBER_RED:
		Amber_Red();
		if (isTimerExpired(18) == 1){
			displayLED();
			setTimer(18, 10);
		}
		if (isTimerExpired(1) == 1){
			counter1--;
			counter2--;
			update7SEG(counter1, counter2);
			setTimer(1, 100);
		}
		if (isTimerExpired(0) == 1){
			state = RED_GREEN;
			counter1 = 7;
			counter2 = 5;
			setTimer(0, 500);
		}
		break;
	case ERROR:
		if (isTimerExpired(3) == 1){
			Error();
			setTimer(3, 50);
		}
		if (isButton1Pressed() == 1){
			state = INIT;
			setTimer(0, 1);
		}
		break;
	default:
		break;
	}
}

