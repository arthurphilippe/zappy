/*
** EPITECH PROJECT, 2018
** PSU_zappy_2017
** File description:
** unreg_player
*/

#include "game.h"
#include "team.h"

void game_unreg_player(game_t *gm, player_t *pl)
{
	team_t * tm = team_find_by_name(gm->ga_teams, pl->p_teamname);

	if (tm) {
		list_find_and_delete_addr(tm->t_membs, pl);
		tm->t_max_memb += 1;
	}
	list_find_and_delete_addr(gm->ga_players, pl);
}
