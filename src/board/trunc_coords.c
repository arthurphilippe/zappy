/*
** EPITECH PROJECT, 2018
** PSU_zappy_2017
** File description:
** trunc_coords
*/

#include "board.h"

void board_trunc_coords(board_t *bd, vector2d_t *coords)
{
	while (coords->v_x < 0)
		coords->v_x = bd->b_max_x + coords->v_x;
	while (coords->v_y < 0)
		coords->v_y = bd->b_max_y + coords->v_y;
	coords->v_x %= bd->b_max_x;
	coords->v_y %= bd->b_max_y;
}
