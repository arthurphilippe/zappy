/*
** EPITECH PROJECT, 2018
** PSU_zappy_2017
** File description:
** take
*/

#include "game.h"

static bool take_food(board_t *bd, player_t *pl)
{
	if (board_get_food(bd, pl->p_pos)) {
		board_dec_food(bd, pl->p_pos);
		player_inventory_add(pl, FOOD);
		return (true);
	}
	return (false);
}

static bool take_stone(board_t *bd, player_t *pl, resource_t resource)
{
	if (board_get_resource(bd, pl->p_pos) == resource) {
		board_put_resource(bd, pl->p_pos, 0);
		player_inventory_add(pl, resource);
		return (true);
	}
	return (false);
}

bool game_take_object(game_t *gm, player_t *pl, resource_t resource)
{
	bool ret;

	if (resource == FOOD) {
		ret = take_food(gm->ga_board, pl);
	} else {
		ret = take_stone(gm->ga_board, pl, resource);
	}
	return (ret);
}

