/*
** EPITECH PROJECT, 2018
** PSU_zappy_2017
** File description:
** create
*/

#include <stdlib.h>
#include "egg.h"
#include "game.h"
#include "player.h"
#include "team.h"

game_t *game_create(unsigned int board_x, unsigned int board_y,
	unsigned int freq, unsigned int max_players)
{
	game_t *game = malloc(sizeof(game_t));

	if (!game)
		return (NULL);
	game->ga_freq = freq;
	game->ga_max_players = max_players;
	game->ga_board = board_create(board_x, board_y);
	game->ga_players = list_create(NULL);
	game->ga_eggs = list_create(egg_delete);
	game->ga_teams = list_create(team_delete);
	chrono_init(&game->ga_board->b_refresh_timer, 0);
	if (!game->ga_board) {
		free(game);
		return (NULL);
	}
	return (game);
}
