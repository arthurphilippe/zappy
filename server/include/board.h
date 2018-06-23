/*
** EPITECH PROJECT, 2018
** PSU_zappy_2017
** File description:
** board
*/

#ifndef BOARD_H_
	#define BOARD_H_

	#include <stddef.h>
	#include <stdbool.h>
	#include "vector2d.h"
	#include "resource.h"
	#include "chrono.h"

	#define BOARD_OK 0
	#define BOARD_ERR -1

/*
** Declaring new board struct
*/
typedef struct		s_board {
	chrono_t	b_refresh_timer;
	unsigned int	**b_data;
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
void board_put_resource(board_t *bd, vector2d_t pos, resource_t resource);
bool board_take_resource(board_t *bd, vector2d_t pos, resource_t resource);
void board_inc_food(board_t *bd, vector2d_t pos);
bool board_dec_food(board_t *bd, vector2d_t pos);
unsigned int *board_get(board_t *bd, vector2d_t pos);
unsigned int board_get_food(board_t *bd, vector2d_t pos);
resource_t board_get_resource(board_t *bd, vector2d_t pos, resource_t res);
void board_trunc_coords(board_t *bd, vector2d_t *coords);
void board_look_at(board_t *bd, game_t *gm, vector2d_t pos, dynbuf_t *buf);

void board_gfx_get_tile_cont(board_t *bd, dynbuf_t *buf, vector2d_t pos);

#endif /* !BOARD_H_ */
