/*
** EPITECH PROJECT, 2018
** PSU_zappy_2017
** File description:
** create
*/

#include <stdlib.h>
#include "game.h"

game_t *game_create(unsigned int board_x, unsigned int board_y,
			unsigned int freq, unsigned int max_players)
{
	game_t *game = malloc(sizeof(game_t));

	if (!game)
		return (NULL);
	(void) board_x;
	(void) board_y;
	game->ga_freq = freq;
	game->ga_max_players = max_players;
	game->ga_board = board_create(board_x, board_y);
	game->ga_players = list_create(free);
	game->ga_teams = list_create(free);
	if (!game->ga_board) {
		free(game);
		return (NULL);
	}
	return (game);
}
