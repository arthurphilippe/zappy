/*
** EPITECH PROJECT, 2018
** PSU_zappy_2017
** File description:
** connect_nbr
*/

#include <stdio.h>
#include "msg.h"
#include "game.h"
#include "team.h"

void msg_cmd_pl_connect_nbr(selector_t *stor, handle_t *hdl, list_t *args)
{
	game_t *gm = stor->s_data;
	player_t *pl = hdl->h_data;
	team_t *tm = team_find_by_name(gm->ga_teams, pl->p_teamname);

	(void) args;
	if (tm) {
		dprintf(hdl->h_fd, "%d\n", tm->t_max_memb);
	}
}
