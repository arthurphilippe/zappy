/*
** EPITECH PROJECT, 2018
** PSU_zappy_2017
** File description:
** game
*/

#include "game.h"
#include "criterion/assert.h"
#include "criterion/criterion.h"
#include "player.h"
#include "team.h"

Test(Game, create)
{
	game_t *game = game_create(20, 15, 3, 6);

	cr_assert(game);
	cr_expect_eq(game->ga_freq, 3);
	cr_expect_eq(game->ga_max_players, 6);
	cr_expect_eq(game->ga_board->b_max_x, 20);
	cr_expect_eq(game->ga_board->b_max_y, 15);
	cr_expect_eq(game->ga_players->l_destructor, NULL);
	cr_expect_eq(game->ga_teams->l_destructor, team_delete);
	cr_expect_eq(game->ga_players->l_size, 0);
	cr_expect_eq(game->ga_teams->l_size, 0);
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
	cr_assert_eq(game_register_player(game, pl), 5);
	cr_assert_eq(game->ga_players->l_size, 1);
	game_delete(game);
}

Test(Game, register_player_max)
{
	game_t *game = game_create(20, 15, 3, 2);
	player_t *pla = player_create();
	player_t *plb = player_create();
	player_t *plc = player_create();

	cr_assert(game);
	cr_assert(pla);
	cr_assert(plb);
	cr_assert(plc);
	pla->p_teamname = strdup("ursidae");
	plb->p_teamname = strdup("ursidae");
	plc->p_teamname = strdup("ursidae");
	cr_assert_eq(game_add_team(game, "ursidae"), 0);
	cr_assert_eq(game->ga_teams->l_size, 1);
	cr_assert_eq(game_register_player(game, pla), 1);
	cr_assert_eq(game->ga_players->l_size, 1);
	cr_assert_eq(game_register_player(game, plb), 0);
	cr_assert_eq(game->ga_players->l_size, 2);
	cr_assert_eq(game_register_player(game, plc), -1);
	cr_assert_eq(game->ga_players->l_size, 2);
	cr_assert_eq(game_register_player(game, plc), -1);
	cr_assert_eq(game->ga_players->l_size, 2);
	player_delete(plc);
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
	cr_assert_eq(game_register_player(game, pl), -1);
	cr_assert_eq(game->ga_players->l_size, 0);
	player_delete(pl);
	game_delete(game);
}

Test(Game, take_food)
{
	player_t *pl = player_create_at((vector2d_t){4, 7});
	game_t *gm = game_create(20, 20, 7, 5);

	cr_assert(pl);
	cr_assert(gm);
	game_add_team(gm, "pandas");
	pl->p_teamname = strdup("pandas");
	cr_assert_neq(game_register_player(gm, pl), -1);

	board_inc_food(gm->ga_board, (vector2d_t){4, 7});
	board_inc_food(gm->ga_board, (vector2d_t){4, 7});
	board_inc_food(gm->ga_board, (vector2d_t){4, 8});
	board_put_resource(gm->ga_board, (vector2d_t){4, 7}, THYSTAME);

	cr_assert_eq(board_get_food(gm->ga_board, pl->p_pos), 2);

	cr_expect(game_take_object(gm, pl, FOOD));
	cr_expect_eq(board_get_food(gm->ga_board, pl->p_pos), 1);
	cr_expect_eq(player_inventory_get(pl, FOOD), 1);
	cr_expect(game_take_object(gm, pl, FOOD));
	cr_expect_eq(board_get_food(gm->ga_board, pl->p_pos), 0);
	cr_expect_eq(player_inventory_get(pl, FOOD), 2);
	cr_expect(!game_take_object(gm, pl, FOOD));
	cr_expect_eq(board_get_food(gm->ga_board, pl->p_pos), 0);
	cr_expect_eq(player_inventory_get(pl, FOOD), 2);
	cr_expect(game_take_object(gm, pl, THYSTAME));
	cr_expect(!game_take_object(gm, pl, THYSTAME));
	cr_expect_eq(player_inventory_get(pl, THYSTAME), 1);
	board_put_resource(gm->ga_board, (vector2d_t){4, 7}, THYSTAME);
	cr_expect(game_take_object(gm, pl, THYSTAME));
	cr_expect_eq(player_inventory_get(pl, THYSTAME), 2);
	game_delete(gm);
}

Test(Game, set_food)
{
	player_t *pl = player_create_at((vector2d_t){4, 7});
	game_t *gm = game_create(20, 20, 7, 5);

	cr_assert(pl);
	cr_assert(gm);
	game_add_team(gm, "pandas");
	pl->p_teamname = strdup("pandas");
	cr_assert_neq(game_register_player(gm, pl), -1);

	board_inc_food(gm->ga_board, (vector2d_t){4, 7});
	board_inc_food(gm->ga_board, (vector2d_t){4, 7});
	board_inc_food(gm->ga_board, (vector2d_t){4, 8});
	board_put_resource(gm->ga_board, (vector2d_t){4, 7}, THYSTAME);

	cr_assert_eq(board_get_food(gm->ga_board, pl->p_pos), 2);

	cr_expect(game_take_object(gm, pl, FOOD));
	cr_expect_eq(board_get_food(gm->ga_board, pl->p_pos), 1);
	cr_expect_eq(player_inventory_get(pl, FOOD), 1);
	cr_expect(game_take_object(gm, pl, FOOD));
	cr_expect_eq(board_get_food(gm->ga_board, pl->p_pos), 0);
	cr_expect_eq(player_inventory_get(pl, FOOD), 2);
	cr_expect(!game_take_object(gm, pl, FOOD));
	cr_expect_eq(board_get_food(gm->ga_board, pl->p_pos), 0);
	cr_expect_eq(player_inventory_get(pl, FOOD), 2);
	cr_expect(game_take_object(gm, pl, THYSTAME));
	cr_expect(!game_take_object(gm, pl, THYSTAME));
	cr_expect_eq(board_get_resource(gm->ga_board, pl->p_pos), 0);
	cr_expect_eq(player_inventory_get(pl, THYSTAME), 1);

	board_put_resource(gm->ga_board, (vector2d_t){4, 7}, THYSTAME);
	cr_expect(game_take_object(gm, pl, THYSTAME));
	cr_expect_eq(player_inventory_get(pl, THYSTAME), 2);
	cr_assert(!game_set_object(gm, pl, SIBUR));
	cr_expect_eq(board_get_resource(gm->ga_board, pl->p_pos), 0);
	cr_assert(game_set_object(gm, pl, THYSTAME));
	cr_expect_eq(board_get_resource(gm->ga_board, pl->p_pos), THYSTAME);
	cr_expect_eq(player_inventory_get(pl, THYSTAME), 1);
	cr_expect_eq(player_inventory_get(pl, SIBUR), 0);

	cr_assert(!game_set_object(gm, pl, THYSTAME));
	cr_expect_eq(board_get_resource(gm->ga_board, pl->p_pos), THYSTAME);
	cr_expect_eq(player_inventory_get(pl, THYSTAME), 1);

	cr_assert(game_set_object(gm, pl, FOOD));
	cr_expect_eq(board_get_food(gm->ga_board, pl->p_pos), 1);
	cr_expect_eq(player_inventory_get(pl, FOOD), 1);
	cr_assert(game_set_object(gm, pl, FOOD));
	cr_expect_eq(board_get_food(gm->ga_board, pl->p_pos), 2);
	cr_expect_eq(player_inventory_get(pl, FOOD), 0);
	cr_assert(!game_set_object(gm, pl, FOOD));

	game_delete(gm);
}

Test(Game, find_pl)
{
	player_t *pl1 = player_create_at((vector2d_t){9, 9});
	player_t *pl2 = player_create_at((vector2d_t){9, 9});
	player_t *pl3 = player_create_at((vector2d_t){9, 9});
	player_t *pl4 = player_create_at((vector2d_t){9, 15});
	game_t *gm = game_create(20, 20, 7, 5);

	cr_assert(pl1);
	cr_assert(pl2);
	cr_assert(pl2);
	cr_assert(gm);
	game_add_team(gm, "pandas");
	game_add_team(gm, "red-pandas");
	pl1->p_teamname = strdup("pandas");
	pl3->p_teamname = strdup("pandas");
	pl2->p_teamname = strdup("red-pandas");
	pl4->p_teamname = strdup("red-pandas");
	cr_assert_neq(game_register_player(gm, pl1), -1);
	cr_assert_neq(game_register_player(gm, pl2), -1);
	cr_assert_neq(game_register_player(gm, pl3), -1);
	cr_assert_neq(game_register_player(gm, pl4), -1);

	player_t *tmp = game_find_pl(gm, 2);
	cr_assert_eq(pl2, tmp);

	tmp = game_find_pl(gm, 675);
	cr_assert_eq(tmp, NULL);

	tmp = game_find_pl(gm, 0);
	cr_assert_eq(tmp, NULL);

	tmp = game_find_pl(gm, 1);
	cr_assert_eq(tmp, pl1);

}
