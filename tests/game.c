/*
** EPITECH PROJECT, 2018
** PSU_zappy_2017
** File description:
** game
*/

#include "game.h"
#include "criterion/assert.h"
#include "criterion/criterion.h"

Test(game, new)
{
	game_t *game = game_create(20, 15, 3, 6);

	cr_assert(game);
	cr_assert_eq(game->ga_freq, 3);
	cr_assert_eq(game->ga_max_players, 6);
	cr_assert_eq(game->ga_board->b_max_x, 20);
	cr_assert_eq(game->ga_board->b_max_y, 15);
	cr_assert_eq(game->ga_players->l_destructor, free);
	cr_assert_eq(game->ga_teams->l_destructor, free);
	cr_assert_eq(game->ga_players->l_size, 0);
	cr_assert_eq(game->ga_teams->l_size, 0);

	game_delete(game);
}
