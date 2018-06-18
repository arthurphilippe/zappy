/*
** EPITECH PROJECT, 2018
** server
** File description:
** find_pl
*/

#include "game.h"
#include "player.h"

player_t *game_find_pl(game_t *gm, int id)
{
	list_iter_t it;
	player_t *pl = NULL;
	int i = 0;

	for (list_iter_init(&it, gm->ga_players, FWD);
		(pl = list_iter_access(&it)); list_iter_next(&it)) {
		if (++i == id)
			return (pl);
	}
	return (pl);
}
