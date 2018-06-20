/*
** EPITECH PROJECT, 2018
** server
** File description:
** find_pl
*/

#include "game.h"
#include "player.h"

player_t *game_find_pl(game_t *gm, unsigned int id)
{
	list_iter_t it;
	player_t *pl = NULL;

	for (list_iter_init(&it, gm->ga_players, FWD);
		(pl = list_iter_access(&it)); list_iter_next(&it)) {
		if (pl->p_id == id)
			return (pl);
	}
	return (pl);
}
