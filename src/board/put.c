/*
** EPITECH PROJECT, 2018
** PSU_zappy_2017
** File description:
** put
*/

#include "board.h"
#include "vector2d.h"
#include "resource.h"

void board_put(board_t *bd, vector2d_t pos, int payload)
{
	size_t idx;

	board_trunc_coords(bd, &pos);
	idx = board_get_idx(bd, pos.v_x, pos.v_y);
	bd->b_data[idx] = payload;
}

void board_put_resource(board_t *bd, vector2d_t pos, resource_t resource)
{
	size_t idx;
	int *tmp;

	board_trunc_coords(bd, &pos);
	idx = board_get_idx(bd, pos.v_x, pos.v_y);
	tmp = &bd->b_data[idx];
	*tmp /= 10;
	*tmp *= 10;
	*tmp += resource;
}
