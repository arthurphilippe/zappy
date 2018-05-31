/*
** EPITECH PROJECT, 2018
** PSU_zappy_2017
** File description:
** get
*/

#include "board.h"

char *board_get_ptr(board_t *bd, vector2d_t pos)
{
	size_t idx = board_get_idx(bd, pos.v_x, pos.v_y);

	return (&bd->b_data[idx]);
}

char board_get(board_t *bd, vector2d_t pos)
{
	size_t idx = board_get_idx(bd, pos.v_x, pos.v_y);

	return (bd->b_data[idx]);
}
