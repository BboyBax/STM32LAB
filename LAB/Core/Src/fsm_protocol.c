/*
 * fsm_protocol.c
 *
 *  Created on: Nov 14, 2025
 *      Author: Ha Trong Son
 */

#include "fsm_protocol.h"

extern ADC_HandleTypeDef hadc1;
extern UART_HandleTypeDef huart2;

Protocol_State protocol_state = PS_IDLE;

uint32_t last_time = 0;
char last_packet[MAX_BUFFER_SIZE];

extern UART_HandleTypeDef huart2;

uint32_t ADC_value = 1234;   // test

void protocol_fsm_init(){
	protocol_state = PS_IDLE;
}
void protocol_fsm_on_event(Protocol_Event ev){
    switch (protocol_state){
        case PS_IDLE:
            if (ev == EVENT_CMD_RST){
                HAL_ADC_Start(&hadc1);
                if (HAL_ADC_PollForConversion(&hadc1, 10) == HAL_OK){
                    ADC_value = HAL_ADC_GetValue(&hadc1);
                }
                sprintf(last_packet, "!ADC=%lu#", ADC_value);
                protocol_state = PS_SEND_ADC;
            }
            break;

        case PS_WAIT_OK:
            if (ev == EVENT_CMD_OK){
                protocol_state = PS_IDLE;
            }
            break;

        default:
            break;
    }
}

void protocol_fsm_run(){
	switch (protocol_state) {

	case PS_IDLE:
		break;

	case PS_SEND_ADC:
        HAL_UART_Transmit(&huart2, (uint8_t*)last_packet, strlen(last_packet), 100);
        last_time = HAL_GetTick();
        protocol_state = PS_WAIT_OK;
        break;

	case PS_WAIT_OK:
        if (HAL_GetTick() - last_time >= 3000){
        	protocol_state = PS_TIMEOUT_RESEND;
        }
        break;

	case PS_TIMEOUT_RESEND:
        HAL_UART_Transmit(&huart2, (uint8_t*)last_packet, strlen(last_packet), 100);
        last_time = HAL_GetTick();
        protocol_state = PS_WAIT_OK;
        break;

	default:
		break;
	}

}

uint32_t get_adc_value(){
	ADC_value = HAL_ADC_GetValue(&hadc1);
	return ADC_value;
}
