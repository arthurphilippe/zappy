/*
** EPITECH PROJECT, 2018
** PSU_zappy_2017
** File description:
** register_player
*/

#include "game.h"
#include "player.h"
#include "team.h"

int game_register_player(game_t *gm, player_t *pl)
{
	static int id = 1;
	team_t *tm = team_find_by_name(gm->ga_teams, pl->p_teamname);

	if (!tm || !tm->t_max_memb ||
		list_push_back(gm->ga_players, pl) != LIST_OK ||
		list_push_back(tm->t_membs, pl) != LIST_OK)
		return (-1);
	pl->p_id = id++;
	return (--tm->t_max_memb);
}
