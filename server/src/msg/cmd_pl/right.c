/*
** EPITECH PROJECT, 2018
** PSU_zappy_2017
** File description:
** right
*/

#include <stdio.h>
#include "msg.h"
#include "player.h"

void msg_cmd_pl_right(selector_t *stor, handle_t *hdl, list_t *args)
{
	player_t *pl = hdl->h_data;

	(void) args;
	(void) stor;
	player_turn_right(pl);
	dprintf(hdl->h_fd, "ok\n");
}
