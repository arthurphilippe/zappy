/*
** EPITECH PROJECT, 2018
** server
** File description:
** get_pl_pos
*/

#include <stdio.h>
#include <stdlib.h>
#include "game.h"
#include "msg.h"
#include "player.h"

static int extract_args(list_t *args, int *pl_id)
{
	if (args->l_size < 1)
		return (-1);
	*pl_id = atoi(args->l_start->n_data);
	return (0);
}

void msg_cmd_gfx_get_pl_lvl(selector_t *stor, handle_t *hdl, list_t *args)
{
	game_t *gm = stor->s_data;
	int pl_id;
	player_t *tmp;

	if (extract_args(args, &pl_id) != 0) {
		dprintf(hdl->h_fd, ASW_BAD_PARAM);
	} else {
		tmp = game_find_pl(gm, pl_id);
		if (tmp)
			dprintf(hdl->h_fd, ASW_PL_LVL, pl_id, tmp->p_lvl);
		else
			dprintf(hdl->h_fd, ASW_BAD_PARAM);
	}
}
