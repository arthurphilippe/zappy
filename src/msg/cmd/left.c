/*
** EPITECH PROJECT, 2018
** PSU_zappy_2017
** File description:
** left
*/

#include <stdio.h>
#include "msg.h"
#include "player.h"

void msg_cmd_left(selector_t *stor, handle_t *hdl, list_t *args)
{
	player_t *pl = hdl->h_data;

	(void) args;
	(void) stor;
	player_turn_left(pl);
	dprintf(hdl->h_fd, "ok\n");
}
