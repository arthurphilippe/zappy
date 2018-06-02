/*
** EPITECH PROJECT, 2018
** PSU_zappy_2017
** File description:
** game
*/

#include "game.h"
#include "player.h"
#include "team.h"
#include "criterion/assert.h"
#include "criterion/criterion.h"

Test(Game, create)
{
	game_t *game = game_create(20, 15, 3, 6);

	cr_assert(game);
	cr_assert_eq(game->ga_freq, 3);
	cr_assert_eq(game->ga_max_players, 6);
	cr_assert_eq(game->ga_board->b_max_x, 20);
	cr_assert_eq(game->ga_board->b_max_y, 15);
	cr_assert_eq(game->ga_players->l_destructor, player_delete);
	cr_assert_eq(game->ga_teams->l_destructor, team_delete);
	cr_assert_eq(game->ga_players->l_size, 0);
	cr_assert_eq(game->ga_teams->l_size, 0);
	game_delete(game);
}

Test(Game, register_player)
{
	game_t *game = game_create(20, 15, 3, 6);
	player_t *pl = player_create();

	cr_assert(game);
	cr_assert(pl);
	pl->p_teamname = strdup("ursidae");
	cr_assert_eq(game_add_team(game, "ursidae"), 0);
	cr_assert_eq(game->ga_teams->l_size, 1);
	cr_assert_eq(game_register_player(game, pl), 0);
	cr_assert_eq(game->ga_players->l_size, 1);
	game_delete(game);
}

Test(Game, register_player_error)
{
	game_t *game = game_create(20, 15, 3, 6);
	player_t *pl = player_create();

	cr_assert(game);
	cr_assert(pl);
	pl->p_teamname = strdup("mucus");
	cr_assert_eq(game_add_team(game, "ursidae"), 0);
	cr_assert_eq(game->ga_teams->l_size, 1);
	cr_assert_neq(game_register_player(game, pl), 0);
	cr_assert_eq(game->ga_players->l_size, 0);
	player_delete(pl);
	game_delete(game);
}

