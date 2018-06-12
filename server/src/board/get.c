/*
** EPITECH PROJECT, 2018
** PSU_zappy_2017
** File description:
** get
*/

#include "board.h"

unsigned int *board_get_ptr(board_t *bd, vector2d_t pos)
{
	size_t idx = board_get_idx(bd, pos.v_x, pos.v_y);

	return (&bd->b_data[idx]);
}

unsigned int board_get(board_t *bd, vector2d_t pos)
{
	size_t idx = board_get_idx(bd, pos.v_x, pos.v_y);

	return (bd->b_data[idx]);
}

resource_t board_get_resource(board_t *bd, vector2d_t pos)
{
	size_t idx = board_get_idx(bd, pos.v_x, pos.v_y);

	return (bd->b_data[idx] % 10);
}

unsigned int board_get_food(board_t *bd, vector2d_t pos)
{
	size_t idx = board_get_idx(bd, pos.v_x, pos.v_y);

	return (bd->b_data[idx] / 10);
}
