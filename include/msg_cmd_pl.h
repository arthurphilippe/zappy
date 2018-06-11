/*
** EPITECH PROJECT, 2018
** PSU_zappy_2017
** File description:
** msg_cmd_pl
*/

#ifndef MSG_CMD_PL_H_
	#define MSG_CMD_PL_H_
	#include "selector.h"

void msg_cmd_pl_forward(selector_t *stor, handle_t *hdl, list_t *args);
void msg_cmd_pl_right(selector_t *stor, handle_t *hdl, list_t *args);
void msg_cmd_pl_left(selector_t *stor, handle_t *hdl, list_t *args);
void msg_cmd_pl_look(selector_t *stor, handle_t *hdl, list_t *args);
void msg_cmd_pl_take(selector_t *stor, handle_t *hdl, list_t *args);
void msg_cmd_pl_set(selector_t *stor, handle_t *hdl, list_t *args);
void msg_cmd_pl_boradcast(selector_t *stor, handle_t *hdl, list_t *args);

#endif /* !MSG_CMD_PL_H_ */
