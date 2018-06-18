/*
** EPITECH PROJECT, 2018
** Zappy
** File description:
** Created by hexa,
*/

#include <memory.h>
#include "team.h"
#include "player.h"

static unsigned int max_level(const unsigned int levels[8])
{
	unsigned int level = (levels[0] >= 1) ? 1 : 0;

	if (levels[5] >= 6 || levels[6] >= 6)
		level = (levels[6] == 6) ? 7 : 6;
	if (levels[3] >= 4 || levels[4] >= 4)
		level = (levels[4] == 4) ? 5 : 4;
	if (levels[1] >= 2 || levels[2] >= 2)
		level = (levels[2] == 2) ? 3 : 2;
	return (level);
}

unsigned int get_max_level_reachable(list_t *teams)
{
	unsigned int levels[8];
	team_t *team;
	player_t *player;
	list_iter_t iter_team;
	list_iter_t iter_player;

	memset(levels, 0, sizeof(int) * 8);
	list_iter_init(&iter_team, teams, FWD);
	while ((team = list_iter_next(&iter_team))) {
		list_iter_init(&iter_player, team->t_membs, FWD);
		while ((player = list_iter_next(&iter_player)))
			levels[player->p_lvl - 1]++;
	}
	return (max_level(levels) + 1);
}