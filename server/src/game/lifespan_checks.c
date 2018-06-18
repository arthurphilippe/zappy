/*
** EPITECH PROJECT, 2018
** server
** File description:
** lifespan_checks
*/

#include "game.h"

void game_lifespan_checks(game_t *gm)
{
	list_iter_t iter;
	player_t *pl;

	list_iter_init(&iter, gm->ga_players, FWD);
	while ((pl = list_iter_next(&iter))) {
		player_lifespan_check(pl);
	}
}
