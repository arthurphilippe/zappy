/*
** EPITECH PROJECT, 2018
** PSU_zappy_2017
** File description:
** init
*/

#include <stdlib.h>
#include "board.h"
#include "resource.h"

static void free_all_prev(unsigned int **tab, unsigned int i)
{
	while (i) {
		free(tab[i--]);
	}
	free(tab[0]);
}

int board_init(board_t *bd, size_t x, size_t y)
{
	bd->b_total_size = x * y;
	bd->b_data = calloc(bd->b_total_size, sizeof(unsigned int *));
	if (!bd->b_data)
		return (BOARD_ERR);
	for (unsigned int i = 0; i < bd->b_total_size; i++) {
		bd->b_data[i] = calloc(RES_COUNT, sizeof(unsigned int));
		if (!bd->b_data[i]) {
			free_all_prev(bd->b_data, i - 1);
			free(bd->b_data);
			return (BOARD_ERR);
		}
	}
	bd->b_max_x = x;
	bd->b_max_y = y;
	return (BOARD_OK);
}
