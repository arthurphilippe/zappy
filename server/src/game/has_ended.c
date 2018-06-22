/*
** EPITECH PROJECT, 2018
** server
** File description:
** has_ended
*/

#include "game.h"
#include "team.h"

static bool check_for_lvls(team_t *tm)
{
	list_iter_t iter;
	player_t *pl;

	list_iter_init(&iter, tm->t_membs, FWD);
	while ((pl = list_iter_next(&iter))) {
		if (pl->p_lvl != 8)
			return (false);
	}
	return (true);
}

bool game_has_ended(game_t *gm)
{
	list_iter_t iter;
	team_t *tm;
	bool ret = false;

	list_iter_init(&iter, gm->ga_teams, FWD);
	while ((tm = list_iter_next(&iter)) && !ret) {
		if (tm->t_membs->l_size >= 6)
			ret = check_for_lvls(tm);
	}
	return (ret);
}
