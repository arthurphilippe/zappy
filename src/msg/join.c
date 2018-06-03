/*
** EPITECH PROJECT, 2018
** PSU_zappy_2017
** File description:
** join
*/

#include <string.h>
#include <stdio.h>
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
	team_t *tm = team_find_by_name(gm->ga_teams, team_name);

	if (!tm) {
		dprintf(hdl->h_fd, "%s: team doesn't exits!\n", team_name);
		return;
	}
	pl->p_teamname = strdup(team_name);
	if (!pl->p_teamname) {
		stor->s_live = false;
		return;
	}
}
