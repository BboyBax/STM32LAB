/*
 * fsm.c
 *
 *  Created on: Oct 3, 2025
 *      Author: Ha Trong Son
 */

#include "fsm.h"


int temp_error = 0;
int temp_red_blink = 0;

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

void Red_Blink(){
	HAL_GPIO_WritePin(GREEN1_GPIO_Port, GREEN1_Pin , SET);
	HAL_GPIO_WritePin(GREEN2_GPIO_Port, GREEN2_Pin , SET);
	HAL_GPIO_WritePin(AMBER2_GPIO_Port, AMBER2_Pin, SET);
	HAL_GPIO_WritePin(AMBER1_GPIO_Port, AMBER1_Pin, SET);
	switch (temp_red_blink) {
		case 0:
			HAL_GPIO_WritePin(RED1_GPIO_Port, RED1_Pin, RESET);
			HAL_GPIO_WritePin(RED2_GPIO_Port, RED2_Pin, RESET);
			temp_red_blink = 1;
			break;
		case 1:
			HAL_GPIO_WritePin(RED1_GPIO_Port, RED1_Pin, SET);
			HAL_GPIO_WritePin(RED2_GPIO_Port, RED2_Pin, SET);
			temp_red_blink = 0;
			break;
		default:
			break;
		}
}

int state = 0;
int mode = 0;
int counter1 = 0;
int counter2 = 0;
int counter = 97;
int value1 = 0;
int value2 = 0;
int mode_state = 0;
int red_counter = 0;


void update_value(int num){
	value1 = num / 10;
	value2 = num % 10;
}

void mode1(){
	switch (state){
		case INIT:
			clear_all_led();
			clear7SEG();
			if (isTimerExpired(0) == 1){
				state = RED_GREEN;
				counter1 = 7;
				counter2 = 5;
				setTimer(0, 500);
			}
			if (isTimerExpired(1) == 1){
				update7SEG(counter1, counter2, counter1, counter2);
				setTimer(1, 100);
			}
			if (isTimerExpired(18) == 1){
				displayLED();
				setTimer(18, 10);
			}
		break;
		case RED_GREEN:
			if (isButtonPressed(0) == 1){
				mode = MODE2;
				setButtonFlag(0);
				setTimer(0, 1);
				setTimer(1, 5);
				setTimer(18, 10);
				break;
			}
			Red_Green();
			if (isTimerExpired(18) == 1){
				displayLED();
				setTimer(18, 10);
			}
			if (isTimerExpired(1) == 1){
				counter1--;
				counter2--;
				update7SEG(counter1, counter2, counter1, counter2);
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
			if (isButtonPressed(0) == 1){
				mode = MODE2;
				setButtonFlag(0);
				setTimer(0, 1);
				setTimer(1, 5);
				setTimer(18, 10);
				break;
			}
			Red_Amber();
			if (isTimerExpired(18) == 1){
				displayLED();
				setTimer(18, 20);
			}
			if (isTimerExpired(1) == 1){
				counter1--;
				counter2--;
				update7SEG(counter1, counter2, counter1, counter2);
				setTimer(1, 100);
			}
			if (isTimerExpired(0) == 1){
				state = GREEN_RED;
				counter1 = 5;
				counter2 = 7;
				setTimer(0, 500);
			}
		break;
		case GREEN_RED:
			if (isButtonPressed(0) == 1){
				mode = MODE2;
				setButtonFlag(0);
				setTimer(0, 1);
				setTimer(1, 5);
				setTimer(18, 10);
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
				update7SEG(counter1, counter2, counter1, counter2);
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
			if (isButtonPressed(0) == 1){
				mode = MODE2;
				setButtonFlag(0);
				setTimer(0, 1);
				setTimer(1, 5);
				setTimer(18, 10);
				break;
			}
			Amber_Red();
			if (isTimerExpired(18) == 1){
				displayLED();
				setTimer(18, 10);
			}
			if (isTimerExpired(1) == 1){
				counter1--;
				counter2--;
				update7SEG(counter1, counter2, counter1, counter2);
				setTimer(1, 100);
			}
			if (isTimerExpired(0) == 1){
				state = RED_GREEN;
				counter1 = 7;
				counter2 = 5;
				setTimer(0, 500);
			}

		break;
		default:
		break;
			}
	return;
}

void mode2(){
	if (isTimerExpired(0) == 1) {
		Red_Blink();
		setTimer(0, 50);
	}
	if (isTimerExpired(1) == 0){
		update7SEG(0, 2, value1, value2);
		setTimer(1, 10);
	}
	if (isTimerExpired(18) == 1){
		displayLED();
		setTimer(18, 10);
	}
}

void mode3(){

}

void mode4(){

}
void fsm_run(){
	if (isTimerExpired(19) == 1){
		setTimer(19, 50);
		HAL_GPIO_TogglePin(LED_BLINK_GPIO_Port, LED_BLINK_Pin);
	}
	setButtonFlag(0);
	switch (mode) {
	case INIT:
		update7SEG(0, 0, 0, 0);
		if (isTimerExpired(18) == 1){
			displayLED();
			setTimer(18, 10);
		}
		if (isButtonPressed(0) == 1){
			mode = MODE1;
			setButtonFlag(0);
			setTimer(0, 1);
			setTimer(1, 5);
			break;
		}
		break;
	case MODE1:
		mode1();
		if (isButtonPressed(0) == 1){
			mode = MODE2;
			setButtonFlag(0);
			setButtonFlag(1);
			setButtonFlag(2);
			setTimer(0, 1);
			setTimer(1, 5);
			setTimer(18, 10);
			break;
		}
		break;
	case MODE2:
		mode2();
		if (isButtonPressed(0) == 1){
			mode = MODE3;
			setButtonFlag(0);
			setTimer(0, 1);
			setTimer(1, 5);
			setTimer(18, 10);
			break;
		}
		if (isButtonPressed(1) == 1){
			counter++;
			if (counter > 99) {
				counter = 0;
			}
			update_value(counter);
			update7SEG(0, 2, value1, value2);
			setButtonFlag(1);
		}
		if (isButtonPressed(2) == 1){
			red_counter = counter;
			setButtonFlag(2);
		}
		break;
	case MODE3:
		mode3();
		break;
	case MODE4:
		mode4();
		break;
	default:
		break;
	}
}

