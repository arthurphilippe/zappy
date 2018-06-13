/*
** EPITECH PROJECT, 2018
** server
** File description:
** get_freq
*/

#include <stdio.h>
#include "msg.h"
#include "game.h"

void msg_cmd_gfx_get_freq(selector_t *stor, handle_t *hdl, list_t *args)
{
	game_t *gm = stor->s_data;

	(void) args;
	dprintf(hdl->h_fd, ASW_GET_FREQ, gm->ga_freq);
}
