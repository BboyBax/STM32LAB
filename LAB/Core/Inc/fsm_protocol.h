/*
 * fsm_protocol.h
 *
 *  Created on: Nov 14, 2025
 *      Author: Ha Trong Son
 */

#ifndef INC_FSM_PROTOCOL_H_
#define INC_FSM_PROTOCOL_H_

#include "main.h"
#include "global.h"

extern ADC_HandleTypeDef hadc1;


void protocol_fsm_init();
void protocol_fsm_on_event(Protocol_Event ev);
void protocol_fsm_run();

uint32_t get_adc_value();

#endif /* INC_FSM_PROTOCOL_H_ */
