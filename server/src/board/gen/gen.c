/*
** EPITECH PROJECT, 2018
** Zappy
** File description:
** Created by hexa,
*/

#include "board_gen.h"

/*static void board_print(board_t *board, resource_t type)
{
	for (size_t y = 0; y < board->b_max_y; ++y) {
		for (size_t x = 0; x < board->b_max_x; ++x) {
			printf("%d ", board->b_data[board_get_idx(board, x, y)][type]);
		}
		printf("\n");
	}
	printf("\n");
}*/

static void board_gen_resource(board_t *board, resource_t type, float percentage)
{
	vector2d_t pos;

	for (int i = 0; i < (board->b_total_size * percentage); i++) {
		pos.v_x = random_int(0, (int)board->b_max_x);
		pos.v_y = random_int(0, (int)board->b_max_y);
		board_put_resource(board, pos, type);
	}
}

void board_gen(board_t *board)
{
	board_gen_resource(board, FOOD, 0.75);
	board_gen_resource(board, LINEMATE, 0.5);
	board_gen_resource(board, DERAUMERE, 0.40);
	board_gen_resource(board, SIBUR, 0.38);
	board_gen_resource(board, MENDIANE, 0.3);
	board_gen_resource(board, PHIRAS, 0.38);
	board_gen_resource(board, THYSTAME, 0.1);
}