/*
** EPITECH PROJECT, 2018
** PSU_zappy_2017
** File description:
** delete
*/

#include <stdlib.h>
#include "game.h"

void game_delete(void *ptr)
{
	game_t *game = ptr;

	list_destroy(game->ga_players);
	list_destroy(game->ga_teams);
	list_destroy(game->ga_eggs);
	board_delete(game->ga_board);
	free(game);
}
