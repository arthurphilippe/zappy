/*
** EPITECH PROJECT, 2018
** PSU_zappy_2017
** File description:
** add_team
*/

#include "team.h"
#include "game.h"

int game_add_team(game_t *gm, const char *name, unsigned int max_memb)
{
	team_t *tm = team_create(name, max_memb);

	if (!tm)
		return (-1);
	return (list_push_back(gm->ga_teams, tm));
}
