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
	#include "resource.h"

	#define BOARD_OK 0
	#define BOARD_ERR -1

/*
** Declaring new board struct
*/
typedef struct		s_board {
	int		*b_data;
	size_t		b_max_x;
	size_t		b_max_y;
	size_t		b_total_size;
}			board_t;

/*
** Forward declarations of dynbuf & game.
*/
typedef struct	s_dynbuf dynbuf_t;
typedef struct	s_game game_t;

/*
** Inlines
*/
static inline size_t board_get_idx(board_t *bd, size_t x, size_t y)
{
	return (y * bd->b_max_x + x);
}

/*
** Protos
*/
board_t *board_create(size_t x, size_t y);
int board_init(board_t *bd, size_t x, size_t y);
void board_delete(void *ptr);
void board_put(board_t *bd, vector2d_t pos, int payload);
void board_put_resource(board_t *bd, vector2d_t pos, resource_t resource);
int *board_get_ptr(board_t *bd, vector2d_t pos);
int board_get(board_t *bd, vector2d_t pos);
resource_t board_get_resource(board_t *bd, vector2d_t pos);
void board_trunc_coords(board_t *bd, vector2d_t *coords);
void board_look_at(board_t *bd, game_t *gm, vector2d_t pos, dynbuf_t *buf);

#endif /* !BOARD_H_ */
