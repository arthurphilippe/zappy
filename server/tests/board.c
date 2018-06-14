/*
** EPITECH PROJECT, 2018
** PSU_zappy_2017
** File description:
** board
*/

#include "board.h"
#include "criterion/assert.h"
#include "criterion/criterion.h"
#include "dynbuf.h"
#include "game.h"
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

Test(Board, put)
{
	board_t *bd = board_create(24, 24);

	cr_assert(bd);
	board_put_resource(bd, (vector2d_t){12, 3}, MENDIANE);
	cr_expect_eq(
		board_get_resource(bd, (vector2d_t){12, 3}, MENDIANE), 1);
	board_take_resource(bd, (vector2d_t){12, 3}, MENDIANE);
	board_take_resource(bd, (vector2d_t){12, 3}, MENDIANE);
	board_take_resource(bd, (vector2d_t){12, 3}, MENDIANE);
	board_take_resource(bd, (vector2d_t){12, 3}, MENDIANE);
	cr_expect_eq(
		board_get_resource(bd, (vector2d_t){12, 3}, MENDIANE), 0);

	board_put_resource(bd, (vector2d_t){12, 3}, MENDIANE);
	board_put_resource(bd, (vector2d_t){12, 3}, MENDIANE);
	board_put_resource(bd, (vector2d_t){12, 3}, MENDIANE);
	board_put_resource(bd, (vector2d_t){12, 3}, MENDIANE);
	board_put_resource(bd, (vector2d_t){12, 3}, MENDIANE);
	board_put_resource(bd, (vector2d_t){12, 3}, MENDIANE);
	board_put_resource(bd, (vector2d_t){12, 3}, MENDIANE);
	board_put_resource(bd, (vector2d_t){12, 3}, MENDIANE);
	board_put_resource(bd, (vector2d_t){12, 3}, MENDIANE);
	board_put_resource(bd, (vector2d_t){12, 3}, MENDIANE);
	board_put_resource(bd, (vector2d_t){12, 3}, MENDIANE);
	board_put_resource(bd, (vector2d_t){12, 3}, MENDIANE);
	board_put_resource(bd, (vector2d_t){12, 3}, MENDIANE);
	board_put_resource(bd, (vector2d_t){12, 3}, MENDIANE);
	board_put_resource(bd, (vector2d_t){12, 3}, MENDIANE);
	cr_expect_eq(
		board_get_resource(bd, (vector2d_t){12, 3}, MENDIANE), 15);
	cr_expect_eq(board_get_food(bd, (vector2d_t){19, 8}), 0);
	board_inc_food(bd, (vector2d_t){19, 8});
	board_inc_food(bd, (vector2d_t){19, 8});
	board_inc_food(bd, (vector2d_t){19, 8});
	cr_expect_eq(board_get_food(bd, (vector2d_t){19, 8}), 3);
	board_dec_food(bd, (vector2d_t){19, 8});
	cr_expect_eq(board_get_food(bd, (vector2d_t){19, 8}), 2);
	board_dec_food(bd, (vector2d_t){19, 8});
	board_dec_food(bd, (vector2d_t){19, 8});
	board_dec_food(bd, (vector2d_t){19, 8});
	board_dec_food(bd, (vector2d_t){19, 8});
	board_dec_food(bd, (vector2d_t){19, 8});
	board_dec_food(bd, (vector2d_t){19, 8});
	board_dec_food(bd, (vector2d_t){19, 8});
	cr_expect_eq(board_get_food(bd, (vector2d_t){19, 8}), 0);

}

Test(Board, truncate_pos)
{
	board_t *bd = board_create(24, 24);
	vector2d_t vec = {12, 26};

	cr_assert(bd);
	board_trunc_coords(bd, &vec);
	cr_expect_eq(vec.v_x, 12);
	cr_expect_eq(vec.v_y, 2);
	vec = (vector2d_t){-76, 2};
	board_trunc_coords(bd, &vec);
	cr_expect_eq(vec.v_y, 2);
	cr_expect_eq(vec.v_x, 20, "got %d", vec.v_x);
	vec = (vector2d_t){2, -75};
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
	board_put_resource(game->ga_board, (vector2d_t){0, 0}, LINEMATE);
	board_put_resource(game->ga_board, (vector2d_t){1, 1}, THYSTAME);
	board_put_resource(game->ga_board, (vector2d_t){1, -1}, SIBUR);

	cr_assert(buf);
	board_look_at(game->ga_board, game, (vector2d_t){0, 0}, buf);
	cr_expect_str_eq(buf->b_data, "linemate player");

	cr_assert(dynbuf_reset(buf) == 0);

	board_look_at(game->ga_board, game, (vector2d_t){1, -1}, buf);
	cr_expect_str_eq(buf->b_data, "sibur");
	game_delete(game);
	dynbuf_delete(buf);
}

Test(Board, gfx_get_tile_cont)
{
	game_t *game = game_create(20, 15, 3, 6);
	dynbuf_t *buf = dynbuf_create();

	cr_assert(game);
	cr_assert(buf);
	board_put_resource(game->ga_board, (vector2d_t){0, 0}, LINEMATE);
	board_put_resource(game->ga_board, (vector2d_t){1, 1}, THYSTAME);
	board_put_resource(game->ga_board, (vector2d_t){1, -1}, SIBUR);
	board_inc_food(game->ga_board, (vector2d_t){4, 7});
	board_inc_food(game->ga_board, (vector2d_t){4, 7});
	board_inc_food(game->ga_board, (vector2d_t){4, 8});
	board_put_resource(game->ga_board, (vector2d_t){4, 7}, THYSTAME);

	board_gfx_get_tile_cont(game->ga_board, buf, (vector2d_t){4, 7});
	cr_expect_str_eq(buf->b_data, "4 7 2 0 0 0 0 0 1");

	board_put_resource(game->ga_board, (vector2d_t){4, 7}, SIBUR);

	dynbuf_reset(buf);
	board_gfx_get_tile_cont(game->ga_board, buf, (vector2d_t){4, 7});
	cr_expect_str_eq(buf->b_data, "4 7 2 0 0 1 0 0 1");

	dynbuf_reset(buf);
	board_put_resource(game->ga_board, (vector2d_t){4, 7}, 0);
	board_gfx_get_tile_cont(game->ga_board, buf, (vector2d_t){4, 7});
	cr_expect_str_eq(buf->b_data, "4 7 3 0 0 1 0 0 1");

	game_delete(game);
	dynbuf_delete(buf);
}
