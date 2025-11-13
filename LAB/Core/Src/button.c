/*
 * button.c
 *
 *  Created on: Nov 13, 2025
 *      Author: Ha Trong Son
 */


#include "button.h"
//int KeyReg0 = NORMAL_STATE;
//int KeyReg1 = NORMAL_STATE;
//int KeyReg2 = NORMAL_STATE;
//int KeyReg3 = NORMAL_STATE;
//
//int TimeOutForKeyPress =  500;
//int button1_pressed = 0;
//int button1_long_pressed = 0;
//int button1_flag = 0;
//
//int button2_pressed = 0;
//int button2_long_pressed = 0;
//int button2_flag = 0;
//
//
//int isButton1Pressed(){
//	if(button1_flag == 1){
//		button1_flag = 0;
//		return 1;
//	}
//	return 0;
//}
//
//int isButton2Pressed(){
//	if(button2_flag == 1){
//		button2_flag = 0;
//		return 1;
//	}
//	return 0;
//}
//
//int isButton1LongPressed(){
//	if(button1_long_pressed == 1){
//		button1_long_pressed = 0;
//		return 1;
//	}
//	return 0;
//}
//
//int isButton2LongPressed(){
//	if(button2_long_pressed == 1){
//		button2_long_pressed = 0;
//		return 1;
//	}
//	return 0;
//}
//
////void subKeyProcess(){
////	//TODO
////	//HAL_GPIO_TogglePin(LED1_GPIO_Port, LED1_Pin);
////	button1_flag = 1;
////}
//
//void getKeyInput(){
//  KeyReg2 = KeyReg1;
//  KeyReg1 = KeyReg0;
//  // Add your key
//  KeyReg0 = HAL_GPIO_ReadPin(BUTTON1_GPIO_Port, BUTTON1_Pin);
//
//
//  if ((KeyReg1 == KeyReg0) && (KeyReg1 == KeyReg2)){
//    if (KeyReg2 != KeyReg3){
//      KeyReg3 = KeyReg2;
//
//      if (KeyReg3 == PRESSED_STATE){
//        TimeOutForKeyPress = 500;
//        //subKeyProcess();
//        button1_flag = 1;
//      }
//
//      // dang nhan de tha ra can viet them
//    }else{
//       TimeOutForKeyPress --;
//        if (TimeOutForKeyPress == 0){
//        	TimeOutForKeyPress = 500;
//        	if (KeyReg3 == PRESSED_STATE){
//        		//subKeyProcess();
//        		button1_flag = 1;
//        	}
//        }
//        // dang nhan de tha ra can viet them
//    }
//  }
//}


// private vars
Button_t buttons[NUM_BUTTONS];

GPIO_TypeDef* BUTTON_PORTS[NUM_BUTTONS] = {
    BUTTON1_GPIO_Port,
    BUTTON2_GPIO_Port,
    BUTTON3_GPIO_Port,
};

uint16_t BUTTON_PINS[NUM_BUTTONS] = {
    BUTTON1_Pin,
    BUTTON2_Pin,
    BUTTON3_Pin,
};

// IMPLEMENTATION

void Button_Init(){
	for (int i = 0; i < NUM_BUTTONS; i++){
		buttons[i].KeyReg0 = NORMAL_STATE;
		buttons[i].KeyReg1 = NORMAL_STATE;
		buttons[i].KeyReg2 = NORMAL_STATE;
		buttons[i].KeyReg3 = NORMAL_STATE;
		buttons[i].TimeOutForKeyPress = 500;
		buttons[i].flag_pressed = 0;
		buttons[i].flag_long_pressed = 0;
	}
}

int isButtonPressed(int index) {
    if (buttons[index].flag_pressed == 1) {
        buttons[index].flag_pressed = 0;
        return 1;
    }
    return 0;
}

int isButtonLongPressed(int index){
	if (buttons[index].flag_long_pressed == 1) {
		buttons[index].flag_long_pressed = 0;
	    return 1;
	}
	return 0;
}

void subKeyProcess(int index){
	buttons[index].flag_pressed = 1;
}

void setButtonFlag(int index){
	buttons[index].flag_pressed = 0;
}

void getKeyInput(){
	for (int i = 0; i < NUM_BUTTONS; i++){
		buttons[i].KeyReg2 = buttons[i].KeyReg1;
		buttons[i].KeyReg1 = buttons[i].KeyReg0;

		buttons[i].KeyReg0 = HAL_GPIO_ReadPin(BUTTON_PORTS[i], BUTTON_PINS[i]);

		if ((buttons[i].KeyReg1 == buttons[i].KeyReg0) && (buttons[i].KeyReg1 == buttons[i].KeyReg2)){
			if (buttons[i].KeyReg2 != buttons[i].KeyReg3){
				buttons[i].KeyReg3 = buttons[i].KeyReg2;

				if (buttons[i].KeyReg3 == PRESSED_STATE){
					buttons[i].TimeOutForKeyPress = 500;
					buttons[i].flag_pressed = 1;
				}
			}
			else {
				buttons[i].TimeOutForKeyPress--;
				if (buttons[i].TimeOutForKeyPress == 0){
					buttons[i].TimeOutForKeyPress = 500;
					if (buttons[i].KeyReg3 == PRESSED_STATE){
						buttons[i].flag_pressed = 1;
					}
				}
			}
		}
	}
}


