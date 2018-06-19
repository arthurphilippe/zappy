/*
** EPITECH PROJECT, 2018
** server
** File description:
** on_cycle
*/

#include "board_gen.h"
#include "game.h"
#include "get_wait_time.h"
#include "selector.h"
#include "team.h"

static void update_board(game_t *gm)
{
	if (chrono_check(&gm->ga_board->b_refresh_timer) == CHRONO_EXPIRED) {
		board_gen(gm->ga_board, gm->ga_teams);
		chrono_init(&gm->ga_board->b_refresh_timer,
			get_wait_time(gm->ga_freq, 50));
	}
}

void game_on_cycle(selector_t *stor)
{
	game_t *game = stor->s_data;

	team_consume_eggs(game->ga_teams, game->ga_eggs);
	// game_lifespan_checks(game);
	update_board(game);
}
