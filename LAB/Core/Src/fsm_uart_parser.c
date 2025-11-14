/*
 * fsm_uart_parser.c
 *
 *  Created on: Nov 14, 2025
 *      Author: Ha Trong Son
 */

#include "fsm_uart_parser.h"

static Parser_State parser_state = PARSE_IDLE;

static char buffer[MAX_BUFFER_SIZE];
static uint8_t index_buf = 0;

void uart_parser_fsm_put_char(char c){
	switch (parser_state){

	case PARSE_IDLE:
		if (c == '!'){
			index_buf = 0;
			buffer[index_buf] = c;
			index_buf++;
			parser_state = PARSE_RECEIVING;
		}
		break;

	case PARSE_RECEIVING:
        if (index_buf < sizeof(buffer)-1){
            buffer[index_buf] = c;
            index_buf++;
        }

        if (c == '#'){
        	buffer[index_buf] = '\0';
        	if (strcmp(buffer, "!RST#") == 0){
        		protocol_fsm_on_event(EVENT_CMD_RST);
        	} else if (strcmp(buffer, "!OK#") == 0){
        		protocol_fsm_on_event(EVENT_CMD_OK);
        	}
        	parser_state = PARSE_IDLE;
        }
        break;

	default:
		break;
	}


}
