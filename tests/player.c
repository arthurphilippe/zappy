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
