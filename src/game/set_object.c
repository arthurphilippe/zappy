/*
** EPITECH PROJECT, 2018
** PSU_zappy_2017
** File description:
** set_object
*/

#include "game.h"

static bool set_food(board_t *bd, player_t *pl)
{
	if (player_inventory_get(pl, FOOD)) {
		player_inventory_rem(pl, FOOD);
		board_inc_food(bd, pl->p_pos);
		return (true);
	}
	return (false);
}

static bool set_stone(board_t *bd, player_t *pl, resource_t resource)
{
	if (player_inventory_get(pl, resource) &&
		!board_get_resource(bd, pl->p_pos)) {
		player_inventory_rem(pl, resource);
		board_put_resource(bd, pl->p_pos, resource);
		return (true);
	}
	return (false);
}

bool game_set_object(game_t *gm, player_t *pl, resource_t resource)
{
	bool ret;

	if (resource == FOOD) {
		ret = set_food(gm->ga_board, pl);
	} else {
		ret = set_stone(gm->ga_board, pl, resource);
	}
	return (ret);
}
