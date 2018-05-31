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

	free(bd->b_data);
	free(bd);
}
