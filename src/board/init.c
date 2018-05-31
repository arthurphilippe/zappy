/*
** EPITECH PROJECT, 2018
** PSU_zappy_2017
** File description:
** init
*/

#include <stdlib.h>
#include "board.h"

int board_init(board_t *bd, size_t x, size_t y)
{
	bd->b_total_size = x * y;
	bd->b_data = malloc(bd->b_total_size);
	if (!bd->b_data)
		return (BOARD_ERR);
	return (BOARD_OK);
}
