/*
** EPITECH PROJECT, 2018
** PSU_zappy_2017
** File description:
** cmd_forward
*/

#include <stdio.h>
#include "msg.h"
#include "player.h"

void msg_cmd_forward(selector_t *stor, handle_t *hdl, list_t *args)
{
	player_t *pl = hdl->h_data;
	board_t *bd = stor->s_data;

	(void) args;
	player_move_foward(pl, bd);
	dprintf(hdl->h_fd, "ok\n");
}
