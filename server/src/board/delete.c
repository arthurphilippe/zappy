/*
** EPITECH PROJECT, 2018
** PSU_zappy_2017
** File description:
** delete
*/

#include <stdlib.h>
#include "board.h"

void board_delete(void *ptr)
{
	board_t *bd = ptr;

	for (unsigned int i = 0; i < bd->b_total_size; i++) {
		free(bd->b_data[i]);
	}
	free(bd->b_data);
	free(bd);
}
