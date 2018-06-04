/*
** EPITECH PROJECT, 2018
** PSU_zappy_2017
** File description:
** main
*/

#include <stdio.h>
#include <stdlib.h>
#include "selector.h"
#include "game.h"
#include "parser.h"

static int start_game_tmp(int port)
{
	selector_t *stor = selector_create();
	game_t *gm = game_create(20, 15, 1, 6);

	if (!stor) {
		game_delete(gm);
		return (84);
	}
	if (!gm) {
		selector_delete(stor);
		return (84);
	}
	game_add_team(gm, "pandas");
	stor->s_data = gm;
	stor->s_delete = game_delete;
	if (listener_create(stor, port)) {
		perror("listener");
		selector_delete(stor);
		return (84);
	}
	selector_loop(stor);
	selector_delete(stor);
	return (0);
}

int main(int ac, char **av)
{
	// if (ac < 2) {
	// 	dprintf(2, "To few arguments.\n");
	// 	return (84);
	// }
	// return (start_game_tmp(atoi(av[1])));
	parser_t *parser = parser_create(ac, av);
	parser_destroy(parser);
}
