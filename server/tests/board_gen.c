/*
** EPITECH PROJECT, 2018
** Zappy
** File description:
** Created by hexa,
*/

#include "board_gen.h"
#include "player.h"
#include "team.h"
#include "list.h"
#include "criterion/assert.h"
#include "criterion/criterion.h"

Test(Board_Gen, count_player)
{
	list_t *teams = list_create(NULL);
	team_t *team1 = team_create("t1", 3);
	team_t *team2 = team_create("t2", 3);
	team_t *team3 = team_create("t3", 3);
	player_t *p1 = player_create();
	player_t *p2 = player_create();
	player_t *p3 = player_create();
	player_t *p4 = player_create();
	player_t *p5 = player_create();
	player_t *p6 = player_create();
	player_t *p7 = player_create();
	player_t *p8 = player_create();
	player_t *p9 = player_create();

	list_push_back(team1->t_membs, p1);
	list_push_back(team1->t_membs, p2);
	list_push_back(team1->t_membs, p3);

	list_push_back(team2->t_membs, p4);
	list_push_back(team2->t_membs, p5);
	list_push_back(team2->t_membs, p6);

	list_push_back(team3->t_membs, p7);
	list_push_back(team3->t_membs, p8);
	list_push_back(team3->t_membs, p9);

	list_push_back(teams, team1);
	list_push_back(teams, team2);
	list_push_back(teams, team3);

	cr_assert_eq(count_players(teams), 9);
}

Test(Board_Gen, max_level_reachable)
{
	list_t *teams = list_create(NULL);
	team_t *team1 = team_create("t1", 3);
	team_t *team2 = team_create("t2", 3);
	team_t *team3 = team_create("t3", 3);
	player_t *p1 = player_create();
	player_t *p2 = player_create();
	player_t *p3 = player_create();
	player_t *p4 = player_create();
	player_t *p5 = player_create();
	player_t *p6 = player_create();
	player_t *p7 = player_create();
	player_t *p8 = player_create();
	player_t *p9 = player_create();

	cr_assert_eq(get_max_level_reachable(teams), 1);

	list_push_back(team1->t_membs, p1);
	list_push_back(team1->t_membs, p2);
	list_push_back(team1->t_membs, p3);

	list_push_back(team2->t_membs, p4);
	list_push_back(team2->t_membs, p5);
	list_push_back(team2->t_membs, p6);

	list_push_back(team3->t_membs, p7);
	list_push_back(team3->t_membs, p8);
	list_push_back(team3->t_membs, p9);

	list_push_back(teams, team1);
	list_push_back(teams, team2);
	list_push_back(teams, team3);

	cr_assert_eq(get_max_level_reachable(teams), 2);

	p1->p_lvl = 3;
	p2->p_lvl = 3;
	cr_assert_eq(get_max_level_reachable(teams), 4);

	p1->p_lvl = 7;
	p2->p_lvl = 7;
	p3->p_lvl = 7;
	p4->p_lvl = 7;
	p5->p_lvl = 7;
	p6->p_lvl = 7;
	cr_assert_eq(get_max_level_reachable(teams), 8);
}

Test(Board_Gen, board_generation)
{
	unsigned int count = 0;
	board_t *board = board_create(12, 12);
	list_t *teams = list_create(NULL);
	team_t *team1 = team_create("t1", 3);
	team_t *team2 = team_create("t2", 3);
	team_t *team3 = team_create("t3", 3);
	player_t *p1 = player_create();
	player_t *p2 = player_create();
	player_t *p3 = player_create();
	player_t *p4 = player_create();
	player_t *p5 = player_create();
	player_t *p6 = player_create();
	player_t *p7 = player_create();
	player_t *p8 = player_create();
	player_t *p9 = player_create();

	list_push_back(team1->t_membs, p1);
	list_push_back(team1->t_membs, p2);
	list_push_back(team1->t_membs, p3);

	list_push_back(team2->t_membs, p4);
	list_push_back(team2->t_membs, p5);
	list_push_back(team2->t_membs, p6);

	list_push_back(team3->t_membs, p7);
	list_push_back(team3->t_membs, p8);
	list_push_back(team3->t_membs, p9);

	list_push_back(teams, team1);
	list_push_back(teams, team2);
	list_push_back(teams, team3);

	board_gen(board, teams);
	for (int i = 0; i < (int)(board->b_max_x * board->b_max_y); i++)
		count += board->b_data[i][LINEMATE];
	cr_assert_eq(count, 9);
	count = 0;
	for (int i = 0; i < (int)(board->b_max_x * board->b_max_y); i++)
		count += board->b_data[i][DERAUMERE];
	cr_assert_eq(count, 0);
	count = 0;

	p1->p_lvl = 3;
	p2->p_lvl = 3;
	board_gen(board, teams);
	for (int i = 0; i < (int)(board->b_max_x * board->b_max_y); i++)
		count += board->b_data[i][PHIRAS];
	cr_assert_eq(count, 9 * 2);
	count = 0;

	p1->p_lvl = 7;
	p2->p_lvl = 7;
	p3->p_lvl = 7;
	p4->p_lvl = 7;
	p5->p_lvl = 7;
	p6->p_lvl = 7;
	board_gen(board, teams);
	for (int i = 0; i < (int)(board->b_max_x * board->b_max_y); i++)
		count += board->b_data[i][THYSTAME];
	cr_assert_eq(count, 9);
	count = 0;
}