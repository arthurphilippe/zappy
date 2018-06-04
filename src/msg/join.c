/*
** EPITECH PROJECT, 2018
** PSU_zappy_2017
** File description:
** join
*/

#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "selector.h"
#include "stolist.h"
#include "msg.h"
#include "player.h"
#include "team.h"
#include "game.h"

void msg_join(selector_t *stor, handle_t *hdl, player_t *pl,
		const char *team_name)
{
	game_t *gm = stor->s_data;
	int ret;

	pl->p_teamname = strdup(team_name);
	if (!pl->p_teamname) {
		stor->s_live = false;
		return;
	}
	ret = game_register_player(gm, pl);
	if (ret == -1) {
		dprintf(hdl->h_fd, "%s: this team may not exist or "
			"may be full.\n",
			team_name);
		free(pl->p_teamname);
		pl->p_teamname = NULL;
	} else {
		dprintf(hdl->h_fd, "%d\n%ld %ld\n", ret,
			gm->ga_board->b_max_x,
			gm->ga_board->b_max_y);
	}
}