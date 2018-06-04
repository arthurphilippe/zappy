/*
** EPITECH PROJECT, 2018
** PSU_zappy_2017
** File description:
** board
*/

#include "board.h"
#include "criterion/assert.h"
#include "criterion/criterion.h"

Test(board, idx)
{
	board_t bd;

	bd.b_max_x = 12;
	cr_expect_eq(board_get_idx(&bd, 10, 0), 10);
	cr_expect_eq(board_get_idx(&bd, 9, 0), 9);
	cr_expect_eq(board_get_idx(&bd, 0, 0), 0);
	cr_expect_eq(board_get_idx(&bd, 0, 1), 12);
	cr_expect_eq(board_get_idx(&bd, 4, 1), 16);
	cr_expect_eq(board_get_idx(&bd, 4, 2), 28);
}

Test(board, get_plain)
{
	board_t bd;
	char *data = malloc(36);

	cr_assert(data);
	data[9] = 'a';
	data[12] = 'b';
	data[24] = 'c';
	data[27] = 'd';
	bd.b_data = data;
	bd.b_max_x = 12;
	size_t idx = board_get_idx(&bd, 10, 0);

	cr_expect_eq(idx, 10);
	cr_expect_eq(board_get(&bd, (vector2d_t){9, 0}), 'a');
	cr_expect_eq(board_get(&bd, (vector2d_t){0, 1}), 'b');
	cr_expect_eq(board_get(&bd, (vector2d_t){0, 2}), 'c');
	cr_expect_eq(board_get(&bd, (vector2d_t){3, 2}), 'd');
	free(data);
}

Test(board, get_pointer)
{
	board_t bd;
	char *data = malloc(36);

	cr_assert(data);
	data[9] = 'a';
	data[12] = 'b';
	data[24] = 'c';
	data[27] = 'd';
	bd.b_data = data;
	bd.b_max_x = 12;
	size_t idx = board_get_idx(&bd, 10, 0);

	cr_expect_eq(idx, 10);
	char *ptr = board_get_ptr(&bd, (vector2d_t){0, 1});

	cr_expect_eq(*ptr, 'b');
	free(data);
}

Test(board, simple_put)
{
	board_t bd;
	char *data = malloc(36);

	cr_assert(data);
	bd.b_data = data;
	bd.b_max_x = 12;
	board_put(&bd, (vector2d_t){9, 0}, 'a');
	board_put(&bd, (vector2d_t){0, 1}, 'b');
	board_put(&bd, (vector2d_t){0, 2}, 'c');
	board_put(&bd, (vector2d_t){3, 2}, 'd');
	board_put(&bd, (vector2d_t){11, 2}, 'e');
	cr_expect_eq(board_get(&bd, (vector2d_t){9, 0}), 'a');
	cr_expect_eq(board_get(&bd, (vector2d_t){0, 1}), 'b');
	cr_expect_eq(board_get(&bd, (vector2d_t){0, 2}), 'c');
	cr_expect_eq(board_get(&bd, (vector2d_t){3, 2}), 'd');
	cr_expect_eq(board_get(&bd, (vector2d_t){11, 2}), 'e');
	free(data);
}

Test(board, truncate_pos)
{
	board_t *bd = board_create(24, 24);
	vector2d_t vec = {12,26};

	cr_assert(bd);
	board_trunc_coords(bd, &vec);
	cr_expect_eq(vec.v_x, 12);
	cr_expect_eq(vec.v_y, 2);
	vec = (vector2d_t) {-76, 2};
	board_trunc_coords(bd, &vec);
	cr_expect_eq(vec.v_y, 2);
	cr_expect_eq(vec.v_x, 20, "got %d", vec.v_x);
	vec = (vector2d_t) {2, -75};
	board_trunc_coords(bd, &vec);
	cr_expect_eq(vec.v_x, 2);
	cr_expect_eq(vec.v_y, 21, "got %d", vec.v_y);
}
