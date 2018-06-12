/*
** EPITECH PROJECT, 2018
** PSU_zappy_2017
** File description:
** add_team
*/

#include "game.h"
#include "team.h"

int game_add_team(game_t *gm, const char *name)
{
	team_t *tm = team_create(name, gm->ga_max_players);

	if (!tm)
		return (-1);
	return (list_push_back(gm->ga_teams, tm));
}
