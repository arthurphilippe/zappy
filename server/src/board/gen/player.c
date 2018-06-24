/*
** EPITECH PROJECT, 2018
** Zappy
** File description:
** Created by hexa,
*/

#include "player.h"
#include "team.h"

unsigned int count_players(list_t *teams)
{
	team_t *tm;
	list_iter_t iter;
	unsigned int count = 0;

	list_iter_init(&iter, teams, FWD);
	while ((tm = list_iter_next(&iter)))
		count += tm->t_membs->l_size;
	return (count);
}

unsigned int count_players_by_level(list_t *teams, unsigned int level)
{
	team_t *tm;
	player_t *pl;
	list_iter_t iter_team;
	list_iter_t iter_player;
	unsigned int count = 0;

	list_iter_init(&iter_team, teams, FWD);
	while ((tm = list_iter_next(&iter_team))) {
		list_iter_init(&iter_player, tm->t_membs, FWD);
		while ((pl = list_iter_next(&iter_player)))
			count = (pl->p_lvl == level) ? count + 1 : count;
	}
	return (count);
}
