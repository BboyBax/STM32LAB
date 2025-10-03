/*
 * display7SEG.c
 *
 *  Created on: Oct 3, 2025
 *      Author: Ha Trong Son
 */

#include "display7SEG.h"


int index_led = 0;
int led_buffer[MAX_LED] = {1, 2, 3, 4};

void clear7SEG(){
	HAL_GPIO_WritePin(EN0_GPIO_Port, EN0_Pin, SET);
	HAL_GPIO_WritePin(EN1_GPIO_Port, EN1_Pin, SET);
	HAL_GPIO_WritePin(EN2_GPIO_Port, EN2_Pin, SET);
	HAL_GPIO_WritePin(EN3_GPIO_Port, EN3_Pin, SET);
}

void display7SEG(int number){
	switch (number) {
	case 0:
		HAL_GPIO_WritePin(GATE_A_GPIO_Port, GATE_A_Pin, RESET);
		HAL_GPIO_WritePin(GATE_B_GPIO_Port, GATE_B_Pin, RESET);
		HAL_GPIO_WritePin(GATE_C_GPIO_Port, GATE_C_Pin, RESET);
		HAL_GPIO_WritePin(GATE_D_GPIO_Port, GATE_D_Pin, RESET);
		HAL_GPIO_WritePin(GATE_E_GPIO_Port, GATE_E_Pin, RESET);
		HAL_GPIO_WritePin(GATE_F_GPIO_Port, GATE_F_Pin, RESET);
		HAL_GPIO_WritePin(GATE_G_GPIO_Port, GATE_G_Pin, SET);
		break;
	case 1:
		HAL_GPIO_WritePin(GATE_A_GPIO_Port, GATE_A_Pin, SET);
		HAL_GPIO_WritePin(GATE_B_GPIO_Port, GATE_B_Pin, RESET);
		HAL_GPIO_WritePin(GATE_C_GPIO_Port, GATE_C_Pin, RESET);
		HAL_GPIO_WritePin(GATE_D_GPIO_Port, GATE_D_Pin, SET);
		HAL_GPIO_WritePin(GATE_E_GPIO_Port, GATE_E_Pin, SET);
		HAL_GPIO_WritePin(GATE_F_GPIO_Port, GATE_F_Pin, SET);
		HAL_GPIO_WritePin(GATE_G_GPIO_Port, GATE_G_Pin, SET);
		break;
	case 2:
		HAL_GPIO_WritePin(GATE_A_GPIO_Port, GATE_A_Pin, RESET);
		HAL_GPIO_WritePin(GATE_B_GPIO_Port, GATE_B_Pin, RESET);
		HAL_GPIO_WritePin(GATE_C_GPIO_Port, GATE_C_Pin, SET);
		HAL_GPIO_WritePin(GATE_D_GPIO_Port, GATE_D_Pin, RESET);
		HAL_GPIO_WritePin(GATE_E_GPIO_Port, GATE_E_Pin, RESET);
		HAL_GPIO_WritePin(GATE_F_GPIO_Port, GATE_F_Pin, SET);
		HAL_GPIO_WritePin(GATE_G_GPIO_Port, GATE_G_Pin, RESET);
		break;
	case 3:
		HAL_GPIO_WritePin(GATE_A_GPIO_Port, GATE_A_Pin, RESET);
		HAL_GPIO_WritePin(GATE_B_GPIO_Port, GATE_B_Pin, RESET);
		HAL_GPIO_WritePin(GATE_C_GPIO_Port, GATE_C_Pin, RESET);
		HAL_GPIO_WritePin(GATE_D_GPIO_Port, GATE_D_Pin, RESET);
		HAL_GPIO_WritePin(GATE_E_GPIO_Port, GATE_E_Pin, SET);
		HAL_GPIO_WritePin(GATE_F_GPIO_Port, GATE_F_Pin, SET);
		HAL_GPIO_WritePin(GATE_G_GPIO_Port, GATE_G_Pin, RESET);
		break;
	case 4:
		HAL_GPIO_WritePin(GATE_A_GPIO_Port, GATE_A_Pin, SET);
		HAL_GPIO_WritePin(GATE_B_GPIO_Port, GATE_B_Pin, RESET);
		HAL_GPIO_WritePin(GATE_C_GPIO_Port, GATE_C_Pin, RESET);
		HAL_GPIO_WritePin(GATE_D_GPIO_Port, GATE_D_Pin, SET);
		HAL_GPIO_WritePin(GATE_E_GPIO_Port, GATE_E_Pin, SET);
		HAL_GPIO_WritePin(GATE_F_GPIO_Port, GATE_F_Pin, RESET);
		HAL_GPIO_WritePin(GATE_G_GPIO_Port, GATE_G_Pin, RESET);
		break;
	case 5:
		HAL_GPIO_WritePin(GATE_A_GPIO_Port, GATE_A_Pin, RESET);
		HAL_GPIO_WritePin(GATE_B_GPIO_Port, GATE_B_Pin, SET);
		HAL_GPIO_WritePin(GATE_C_GPIO_Port, GATE_C_Pin, RESET);
		HAL_GPIO_WritePin(GATE_D_GPIO_Port, GATE_D_Pin, RESET);
		HAL_GPIO_WritePin(GATE_E_GPIO_Port, GATE_E_Pin, SET);
		HAL_GPIO_WritePin(GATE_F_GPIO_Port, GATE_F_Pin, RESET);
		HAL_GPIO_WritePin(GATE_G_GPIO_Port, GATE_G_Pin, RESET);
		break;
	case 6:
		HAL_GPIO_WritePin(GATE_A_GPIO_Port, GATE_A_Pin, RESET);
		HAL_GPIO_WritePin(GATE_B_GPIO_Port, GATE_B_Pin, SET);
		HAL_GPIO_WritePin(GATE_C_GPIO_Port, GATE_C_Pin, RESET);
		HAL_GPIO_WritePin(GATE_D_GPIO_Port, GATE_D_Pin, RESET);
		HAL_GPIO_WritePin(GATE_E_GPIO_Port, GATE_E_Pin, RESET);
		HAL_GPIO_WritePin(GATE_F_GPIO_Port, GATE_F_Pin, RESET);
		HAL_GPIO_WritePin(GATE_G_GPIO_Port, GATE_G_Pin, RESET);
		break;
	case 7:
		HAL_GPIO_WritePin(GATE_A_GPIO_Port, GATE_A_Pin, RESET);
		HAL_GPIO_WritePin(GATE_B_GPIO_Port, GATE_B_Pin, RESET);
		HAL_GPIO_WritePin(GATE_C_GPIO_Port, GATE_C_Pin, RESET);
		HAL_GPIO_WritePin(GATE_D_GPIO_Port, GATE_D_Pin, SET);
		HAL_GPIO_WritePin(GATE_E_GPIO_Port, GATE_E_Pin, SET);
		HAL_GPIO_WritePin(GATE_F_GPIO_Port, GATE_F_Pin, SET);
		HAL_GPIO_WritePin(GATE_G_GPIO_Port, GATE_G_Pin, SET);
		break;
	case 8:
		HAL_GPIO_WritePin(GATE_A_GPIO_Port, GATE_A_Pin, RESET);
		HAL_GPIO_WritePin(GATE_B_GPIO_Port, GATE_B_Pin, RESET);
		HAL_GPIO_WritePin(GATE_C_GPIO_Port, GATE_C_Pin, RESET);
		HAL_GPIO_WritePin(GATE_D_GPIO_Port, GATE_D_Pin, RESET);
		HAL_GPIO_WritePin(GATE_E_GPIO_Port, GATE_E_Pin, RESET);
		HAL_GPIO_WritePin(GATE_F_GPIO_Port, GATE_F_Pin, RESET);
		HAL_GPIO_WritePin(GATE_G_GPIO_Port, GATE_G_Pin, RESET);
		break;
	case 9:
		HAL_GPIO_WritePin(GATE_A_GPIO_Port, GATE_A_Pin, RESET);
		HAL_GPIO_WritePin(GATE_B_GPIO_Port, GATE_B_Pin, RESET);
		HAL_GPIO_WritePin(GATE_C_GPIO_Port, GATE_C_Pin, RESET);
		HAL_GPIO_WritePin(GATE_D_GPIO_Port, GATE_D_Pin, RESET);
		HAL_GPIO_WritePin(GATE_E_GPIO_Port, GATE_E_Pin, SET);
		HAL_GPIO_WritePin(GATE_F_GPIO_Port, GATE_F_Pin, RESET);
		HAL_GPIO_WritePin(GATE_G_GPIO_Port, GATE_G_Pin, RESET);
		break;
	default:
		break;
	}
	return;
}

void update7SEG(int counter1, int counter2, int counter3, int counter4){
	led_buffer[0] = counter1;
	led_buffer[1] = counter2;
	led_buffer[2] = counter3;
	led_buffer[3] = counter4;
}

void displayLED(){
	switch (index_led) {
	case 0:
		HAL_GPIO_WritePin(EN0_GPIO_Port, EN0_Pin, RESET);
		HAL_GPIO_WritePin(EN1_GPIO_Port, EN1_Pin, SET);
		HAL_GPIO_WritePin(EN2_GPIO_Port, EN2_Pin, SET);
		HAL_GPIO_WritePin(EN3_GPIO_Port, EN3_Pin, SET);
		display7SEG(led_buffer[index_led]);
		index_led++;
		break;
	case 1:
		HAL_GPIO_WritePin(EN0_GPIO_Port, EN0_Pin, SET);
		HAL_GPIO_WritePin(EN1_GPIO_Port, EN1_Pin, RESET);
		HAL_GPIO_WritePin(EN2_GPIO_Port, EN2_Pin, SET);
		HAL_GPIO_WritePin(EN3_GPIO_Port, EN3_Pin, SET);
		display7SEG(led_buffer[index_led]);
		index_led++;
		break;
	case 2:
		HAL_GPIO_WritePin(EN0_GPIO_Port, EN0_Pin, SET);
		HAL_GPIO_WritePin(EN1_GPIO_Port, EN1_Pin, SET);
		HAL_GPIO_WritePin(EN2_GPIO_Port, EN2_Pin, RESET);
		HAL_GPIO_WritePin(EN3_GPIO_Port, EN3_Pin, SET);
		display7SEG(led_buffer[index_led]);
		index_led++;
		break;
	case 3:
		HAL_GPIO_WritePin(EN0_GPIO_Port, EN0_Pin, SET);
		HAL_GPIO_WritePin(EN1_GPIO_Port, EN1_Pin, SET);
		HAL_GPIO_WritePin(EN2_GPIO_Port, EN2_Pin, SET);
		HAL_GPIO_WritePin(EN3_GPIO_Port, EN3_Pin, RESET);
		display7SEG(led_buffer[index_led]);
		index_led = 0;
		break;
	default:
		break;
	}
}
