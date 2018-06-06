/*
** EPITECH PROJECT, 2018
** PSU_zappy_2017
** File description:
** put
*/

#include "board.h"
#include "vector2d.h"

void board_put(board_t *bd, vector2d_t pos, char payload)
{
	size_t idx;

	board_trunc_coords(bd, &pos);
	idx = board_get_idx(bd, pos.v_x, pos.v_y);
	bd->b_data[idx] = payload;
}
