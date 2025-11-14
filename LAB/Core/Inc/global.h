/*
 * global.h
 *
 *  Created on: Nov 14, 2025
 *      Author: Ha Trong Son
 */

#ifndef INC_GLOBAL_H_
#define INC_GLOBAL_H_

#define MAX_BUFFER_SIZE 	30

typedef enum {
	EVENT_CMD_RST,
	EVENT_CMD_OK
} Protocol_Event;

typedef enum {
    PS_IDLE,
    PS_SEND_ADC,
    PS_WAIT_OK,
    PS_TIMEOUT_RESEND
} Protocol_State;

typedef enum {
    PARSE_IDLE,
    PARSE_RECEIVING
} Parser_State;

#endif /* INC_GLOBAL_H_ */
