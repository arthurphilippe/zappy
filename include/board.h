/*
** EPITECH PROJECT, 2018
** PSU_zappy_2017
** File description:
** board
*/

#ifndef BOARD_H_
	#define BOARD_H_

	#include <stddef.h>
	#include "vector2d.h"

	#define BOARD_OK 0
	#define BOARD_ERR -1

typedef struct		s_board {
	char		*b_data;
	size_t		b_max_x;
	size_t		b_max_y;
	size_t		b_total_size;
}			board_t;

static inline size_t board_get_idx(board_t *bd, size_t x, size_t y)
{
	return (y * bd->b_max_x + x);
}

board_t *board_create(size_t x, size_t y);
int board_init(board_t *bd, size_t x, size_t y);
void board_delete(void *ptr);
void board_put(board_t *bd, vector2d_t pos, char payload);
char *board_get_ptr(board_t *bd, vector2d_t pos);
char board_get(board_t *bd, vector2d_t pos);

#endif /* !BOARD_H_ */
