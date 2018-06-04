/*
** EPITECH PROJECT, 2018
** PSU_zappy_2017
** File description:
** player
*/

#include <criterion/criterion.h>
#include <criterion/assert.h>
#include "player.h"
#include "board.h"

Test(Player, create)
{
	player_t *pl = player_create();

	cr_assert(pl);
	cr_assert_eq(pl->p_id, 1);
	player_delete(pl);
}

Test(Player, id)
{
	player_t *pl = player_create();

	cr_assert(pl);
	cr_assert_eq(pl->p_id, 1);
	player_delete(pl);
	pl = player_create();
	cr_assert_eq(pl->p_id, 2);
	player_delete(pl);
	pl = player_create();
	cr_assert_eq(pl->p_id, 3);
	player_delete(pl);
	pl = player_create();
	cr_assert_eq(pl->p_id, 4);
	player_delete(pl);
}

Test(Player, Move) {
	player_t *pl = player_create_at((vector2d_t) {12, 12});
	board_t *bd = board_create(24, 24);

	cr_assert_eq(pl->p_pos.v_x, 12);
	cr_assert_eq(pl->p_pos.v_y, 12);
	player_move_foward(pl, bd);
	cr_assert_eq(pl->p_pos.v_x, 13);
	cr_assert_eq(pl->p_pos.v_y, 12);
	player_move_foward(pl, bd);
	cr_assert_eq(pl->p_pos.v_x, 14);
	cr_assert_eq(pl->p_pos.v_y, 12);
	player_move_foward(pl, bd);
	cr_assert_eq(pl->p_pos.v_x, 15);
	cr_assert_eq(pl->p_pos.v_y, 12);
	player_move_foward(pl, bd);
	cr_assert_eq(pl->p_pos.v_x, 16);
	cr_assert_eq(pl->p_pos.v_y, 12);
	player_move_foward(pl, bd);
	cr_assert_eq(pl->p_pos.v_x, 17);
	cr_assert_eq(pl->p_pos.v_y, 12);
	player_move_foward(pl, bd);
	cr_assert_eq(pl->p_pos.v_x, 18);
	cr_assert_eq(pl->p_pos.v_y, 12);
	player_move_foward(pl, bd);
	cr_assert_eq(pl->p_pos.v_x, 19);
	cr_assert_eq(pl->p_pos.v_y, 12);
	player_move_foward(pl, bd);
	cr_assert_eq(pl->p_pos.v_x, 20);
	cr_assert_eq(pl->p_pos.v_y, 12);
	player_move_foward(pl, bd);
	cr_assert_eq(pl->p_pos.v_x, 21);
	cr_assert_eq(pl->p_pos.v_y, 12);
	player_move_foward(pl, bd);
	cr_assert_eq(pl->p_pos.v_x, 22);
	cr_assert_eq(pl->p_pos.v_y, 12);
	player_move_foward(pl, bd);
	cr_assert_eq(pl->p_pos.v_x, 23);
	cr_assert_eq(pl->p_pos.v_y, 12);
	player_move_foward(pl, bd);
	cr_assert_eq(pl->p_pos.v_x, 0);
	cr_assert_eq(pl->p_pos.v_y, 12);
	player_move_foward(pl, bd);
	cr_assert_eq(pl->p_pos.v_x, 1);
	cr_assert_eq(pl->p_pos.v_y, 12);
	player_move_foward(pl, bd);
	cr_assert_eq(pl->p_pos.v_x, 2);
	cr_assert_eq(pl->p_pos.v_y, 12);
}

Test(Player, MoveUp) {
	player_t *pl = player_create_at((vector2d_t) {12, 12});
	board_t *bd = board_create(24, 24);

	pl->p_dir = (vector2d_t) {0, -1};
	cr_assert_eq(pl->p_pos.v_y, 12);
	cr_assert_eq(pl->p_pos.v_x, 12);
	player_move_foward(pl, bd);
	cr_assert_eq(pl->p_pos.v_y, 11);
	cr_assert_eq(pl->p_pos.v_x, 12);
	player_move_foward(pl, bd);
	cr_assert_eq(pl->p_pos.v_y, 10);
	cr_assert_eq(pl->p_pos.v_x, 12);
	player_move_foward(pl, bd);
	cr_assert_eq(pl->p_pos.v_y, 9);
	cr_assert_eq(pl->p_pos.v_x, 12);
	player_move_foward(pl, bd);
	cr_assert_eq(pl->p_pos.v_y, 8);
	cr_assert_eq(pl->p_pos.v_x, 12);
	player_move_foward(pl, bd);
	cr_assert_eq(pl->p_pos.v_y, 7);
	cr_assert_eq(pl->p_pos.v_x, 12);
	player_move_foward(pl, bd);
	cr_assert_eq(pl->p_pos.v_y, 6);
	cr_assert_eq(pl->p_pos.v_x, 12);
	player_move_foward(pl, bd);
	cr_assert_eq(pl->p_pos.v_y, 5);
	cr_assert_eq(pl->p_pos.v_x, 12);
	player_move_foward(pl, bd);
	cr_assert_eq(pl->p_pos.v_y, 4);
	cr_assert_eq(pl->p_pos.v_x, 12);
	player_move_foward(pl, bd);
	cr_assert_eq(pl->p_pos.v_y, 3);
	cr_assert_eq(pl->p_pos.v_x, 12);
	player_move_foward(pl, bd);
	cr_assert_eq(pl->p_pos.v_y, 2);
	cr_assert_eq(pl->p_pos.v_x, 12);
	player_move_foward(pl, bd);
	cr_assert_eq(pl->p_pos.v_y, 1);
	cr_assert_eq(pl->p_pos.v_x, 12);
	player_move_foward(pl, bd);
	cr_assert_eq(pl->p_pos.v_y, 0);
	cr_assert_eq(pl->p_pos.v_x, 12);
	player_move_foward(pl, bd);
	cr_assert_eq(pl->p_pos.v_y, 23, "got %d", pl->p_pos.v_y);
	cr_assert_eq(pl->p_pos.v_x, 12);
	player_move_foward(pl, bd);
	cr_assert_eq(pl->p_pos.v_y, 22);
	cr_assert_eq(pl->p_pos.v_x, 12);
	player_move_foward(pl, bd);
	cr_assert_eq(pl->p_pos.v_y, 21);
	cr_assert_eq(pl->p_pos.v_x, 12);
}

Test(Player, MoveLeft) {
	player_t *pl = player_create_at((vector2d_t) {12, 12});
	board_t *bd = board_create(24, 24);

	pl->p_dir = (vector2d_t) {-1, 0};
	cr_assert_eq(pl->p_pos.v_x, 12);
	cr_assert_eq(pl->p_pos.v_y, 12);
	player_move_foward(pl, bd);
	cr_assert_eq(pl->p_pos.v_x, 11);
	cr_assert_eq(pl->p_pos.v_y, 12);
	player_move_foward(pl, bd);
	cr_assert_eq(pl->p_pos.v_x, 10);
	cr_assert_eq(pl->p_pos.v_y, 12);
	player_move_foward(pl, bd);
	cr_assert_eq(pl->p_pos.v_x, 9);
	cr_assert_eq(pl->p_pos.v_y, 12);
	player_move_foward(pl, bd);
	cr_assert_eq(pl->p_pos.v_x, 8);
	cr_assert_eq(pl->p_pos.v_y, 12);
	player_move_foward(pl, bd);
	cr_assert_eq(pl->p_pos.v_x, 7);
	cr_assert_eq(pl->p_pos.v_y, 12);
	player_move_foward(pl, bd);
	cr_assert_eq(pl->p_pos.v_x, 6);
	cr_assert_eq(pl->p_pos.v_y, 12);
	player_move_foward(pl, bd);
	cr_assert_eq(pl->p_pos.v_x, 5);
	cr_assert_eq(pl->p_pos.v_y, 12);
	player_move_foward(pl, bd);
	cr_assert_eq(pl->p_pos.v_x, 4);
	cr_assert_eq(pl->p_pos.v_y, 12);
	player_move_foward(pl, bd);
	cr_assert_eq(pl->p_pos.v_x, 3);
	cr_assert_eq(pl->p_pos.v_y, 12);
	player_move_foward(pl, bd);
	cr_assert_eq(pl->p_pos.v_x, 2);
	cr_assert_eq(pl->p_pos.v_y, 12);
	player_move_foward(pl, bd);
	cr_assert_eq(pl->p_pos.v_x, 1);
	cr_assert_eq(pl->p_pos.v_y, 12);
	player_move_foward(pl, bd);
	cr_assert_eq(pl->p_pos.v_x, 0);
	cr_assert_eq(pl->p_pos.v_y, 12);
	player_move_foward(pl, bd);
	cr_assert_eq(pl->p_pos.v_x, 23, "got %d", pl->p_pos.v_x);
	cr_assert_eq(pl->p_pos.v_y, 12);
	player_move_foward(pl, bd);
	cr_assert_eq(pl->p_pos.v_x, 22);
	cr_assert_eq(pl->p_pos.v_y, 12);
	player_move_foward(pl, bd);
	cr_assert_eq(pl->p_pos.v_x, 21);
	cr_assert_eq(pl->p_pos.v_y, 12);
}

Test(Player, TurnRight)
{
	player_t *pl = player_create_at((vector2d_t) {12, 12});

	pl->p_dir = (vector2d_t) {1, 0};
	player_turn_right(pl);
	cr_assert_eq(pl->p_dir.v_x, 0);
	cr_assert_eq(pl->p_dir.v_y, -1);
	player_turn_right(pl);
	cr_assert_eq(pl->p_dir.v_x, -1);
	cr_assert_eq(pl->p_dir.v_y, 0);
	player_turn_right(pl);
	cr_assert_eq(pl->p_dir.v_x, 0);
	cr_assert_eq(pl->p_dir.v_y, 1);
	player_turn_right(pl);
	cr_assert_eq(pl->p_dir.v_x, 1);
	cr_assert_eq(pl->p_dir.v_y, 0);
}

Test(Player, TurnLeft)
{
	player_t *pl = player_create_at((vector2d_t) {12, 12});

	pl->p_dir = (vector2d_t) {1, 0};
	player_turn_left(pl);
	cr_assert_eq(pl->p_dir.v_x, 0);
	cr_assert_eq(pl->p_dir.v_y, 1);
	player_turn_left(pl);
	cr_assert_eq(pl->p_dir.v_x, -1);
	cr_assert_eq(pl->p_dir.v_y, 0);
	player_turn_left(pl);
	cr_assert_eq(pl->p_dir.v_x, 0);
	cr_assert_eq(pl->p_dir.v_y, -1);
	player_turn_left(pl);
	cr_assert_eq(pl->p_dir.v_x, 1);
	cr_assert_eq(pl->p_dir.v_y, 0);
}

