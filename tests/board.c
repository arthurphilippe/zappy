/*
** EPITECH PROJECT, 2018
** PSU_zappy_2017
** File description:
** board
*/

#include "board.h"
#include "criterion/assert.h"
#include "criterion/criterion.h"
#include "game.h"
#include "dynbuf.h"
#include "resource.h"

Test(Board, idx)
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

Test(Board, get_plain)
{
	board_t bd;
	int *data = malloc(sizeof(int) * 36);

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

Test(Board, get_pointer)
{
	board_t bd;
	int *data = malloc(sizeof(int) * 36);

	cr_assert(data);
	data[9] = 'a';
	data[12] = 'b';
	data[24] = 'c';
	data[27] = 'd';
	bd.b_data = data;
	bd.b_max_x = 12;
	size_t idx = board_get_idx(&bd, 10, 0);

	cr_expect_eq(idx, 10);
	int *ptr = board_get_ptr(&bd, (vector2d_t){0, 1});

	cr_expect_eq(*ptr, 'b');
	free(data);
}

Test(Board, simple_put)
{
	board_t bd;
	int *data = calloc(36, sizeof(int));

	cr_assert(data);
	bd.b_data = data;
	bd.b_max_x = 12;
	bd.b_max_y = 12;
	board_put(&bd, (vector2d_t){9, 0}, 'a');
	board_put(&bd, (vector2d_t){0, 1}, 'b');
	board_put(&bd, (vector2d_t){0, 2}, 'c');
	board_put(&bd, (vector2d_t){3, 2}, 'd');
	board_put(&bd, (vector2d_t){11, 2}, 'e');
	board_put_resource(&bd, (vector2d_t){4, 2}, PHIRAS);
	cr_expect_eq(board_get(&bd, (vector2d_t){9, 0}), 'a', "got %c", board_get(&bd, (vector2d_t){9, 0}));
	cr_expect_eq(board_get(&bd, (vector2d_t){0, 1}), 'b', "got %c", board_get(&bd, (vector2d_t){0, 1}));
	cr_expect_eq(board_get(&bd, (vector2d_t){0, 2}), 'c', "got %c", board_get(&bd, (vector2d_t){0, 2}));
	cr_expect_eq(board_get(&bd, (vector2d_t){3, 2}), 'd', "got %c", board_get(&bd, (vector2d_t){3, 2}));
	cr_expect_eq(board_get(&bd, (vector2d_t){11, 2}), 'e', "got %c", board_get(&bd, (vector2d_t){11, 2}));
	int test = board_get_resource(&bd, (vector2d_t){4, 2});
	cr_assert_eq(test, PHIRAS);
	cr_expect_eq(board_get_resource(&bd, (vector2d_t){4, 2}), PHIRAS);
	free(data);
}

Test(Board, truncate_pos)
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
	board_delete(bd);
}

Test(Board, look_at_1)
{
	game_t *game = game_create(20, 15, 3, 6);
	player_t *pl = player_create();

	pl->p_teamname = strdup("ursidae");
	cr_expect_eq(game_add_team(game, "ursidae"), 0);
	cr_expect_eq(game->ga_teams->l_size, 1);
	cr_expect_eq(game_register_player(game, pl), 5);
	cr_expect_eq(game->ga_players->l_size, 1);

	dynbuf_t *buf = dynbuf_create();
	board_put_resource(game->ga_board, (vector2d_t) {0, 0}, INEMATE);
	board_put_resource(game->ga_board, (vector2d_t) {1, 1}, THYSTAME);
	board_put_resource(game->ga_board, (vector2d_t) {1, -1}, SIBUR);

	cr_assert(buf);
	board_look_at(game->ga_board, game, (vector2d_t) {0, 0}, buf);
	cr_expect_str_eq(buf->b_data, "inemate player");

	cr_assert(dynbuf_reset(buf) == 0);

	board_look_at(game->ga_board, game, (vector2d_t) {1, -1}, buf);
	cr_expect_str_eq(buf->b_data, "sibur");
	game_delete(game);
	dynbuf_delete(buf);
}
