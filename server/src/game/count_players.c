/*
** EPITECH PROJECT, 2018
** server
** File description:
** count_players
*/

#include "game.h"

unsigned int game_count_players(game_t *gm, vector2d_t pos)
{
	list_iter_t iter;
	player_t *pl;
	unsigned int count = 0;

	list_iter_init(&iter, gm->ga_players, FWD);
	while ((pl = list_iter_next(&iter))) {
		if (pl->p_pos.v_x == pos.v_x && pl->p_pos.v_y == pos.v_y)
			count += 1;
	}
	return (count);
}

unsigned int game_count_players_lvl(game_t *gm, player_t *pl)
{
	list_iter_t iter;
	player_t *tmp;
	unsigned int count = 0;

	list_iter_init(&iter, gm->ga_players, FWD);
	while ((tmp = list_iter_next(&iter))) {
		if (tmp->p_lvl == pl->p_lvl &&
			tmp->p_pos.v_x == pl->p_pos.v_x &&
			tmp->p_pos.v_y == pl->p_pos.v_y)
			count += 1;
	}
	return (count);
}
