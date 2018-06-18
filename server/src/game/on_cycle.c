/*
** EPITECH PROJECT, 2018
** server
** File description:
** on_cycle
*/

#include "game.h"
#include "selector.h"
#include "team.h"

void game_on_cycle(selector_t *stor)
{
	game_t *game = stor->s_data;

	team_consume_eggs(game->ga_teams, game->ga_eggs);
	game_lifespan_checks(game);
}
