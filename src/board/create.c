/*
** EPITECH PROJECT, 2018
** PSU_zappy_2017
** File description:
** create
*/

#include <stdlib.h>
#include "board.h"

board_t *board_create(size_t x, size_t y)
{
	board_t *board = malloc(sizeof(board_t));

	if (!board)
		return (NULL);
	if (board_init(board, x, y) != BOARD_OK) {
		free(board);
		return (NULL);
	}
	return (board);
}
