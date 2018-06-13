/*
** EPITECH PROJECT, 2018
** server
** File description:
** get_freq
*/

#include <stdlib.h>
#include <stdio.h>
#include "msg.h"
#include "game.h"

static int extract_args(list_t *args, unsigned int *pl_id)
{
	if (args->l_size < 1)
		return (-1);
	*pl_id = atoi(args->l_start->n_data);
	return (0);
}

void msg_cmd_gfx_set_freq(selector_t *stor, handle_t *hdl, list_t *args)
{
	game_t *gm = stor->s_data;

	if (extract_args(args, &gm->ga_freq) == 0)
		dprintf(hdl->h_fd, ASW_SET_FREQ, gm->ga_freq);
	else
		dprintf(hdl->h_fd, ASW_BAD_PARAM);
}
