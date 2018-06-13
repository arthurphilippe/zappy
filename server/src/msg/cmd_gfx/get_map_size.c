/*
** EPITECH PROJECT, 2018
** server
** File description:
** get_map_size
*/

#include <stdio.h>
#include "game.h"
#include "msg.h"

void msg_cmd_gfx_get_map_size(selector_t *stor, handle_t *hdl, list_t *args)
{
	game_t *gm = stor->s_data;

	(void) args;
	dprintf(hdl->h_fd, ASW_MAP_SIZE, gm->ga_board->b_max_x,
		gm->ga_board->b_max_y);
}
