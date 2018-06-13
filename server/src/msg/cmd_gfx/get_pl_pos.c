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

static const vector2d_t *get_pl_pos_by_id(list_t *players, int id)
{
	list_iter_t it;
	player_t *pl;

	for (list_iter_init(&it, players, FWD); (pl = list_iter_access(&it));
		list_iter_next(&it)) {
		if (pl->p_id == id)
			return (&pl->p_pos);
	}
	return (NULL);
}

void msg_cmd_gfx_get_pl_pos(selector_t *stor, handle_t *hdl, list_t *args)
{
	game_t *gm = stor->s_data;
	int pl_id;
	const vector2d_t *pos;

	if (extract_args(args, &pl_id) != 0) {
		dprintf(hdl->h_fd, ASW_BAD_PARAM);
	} else {
		pos = get_pl_pos_by_id(gm->ga_players, pl_id);
		if (pos)
			dprintf(hdl->h_fd, ASW_PL_POS, pl_id, pos->v_x,
				pos->v_y, "salut");
		else
			dprintf(hdl->h_fd, ASW_BAD_PARAM);
	}
}
