/*
** EPITECH PROJECT, 2018
** zappy
** File description:
** parser
*/

#include <stdio.h>
#include <stdbool.h>
#include "parser.h"
#include "color.h"

static bool parser_check(parser_t *game_info)
{
	if ((game_info->client_nb) && (game_info->freq) && (game_info->height)
		&& (game_info->port) && list_get_size(game_info->team_name) &&
		(game_info->width))
		return (true);
	else {
		parser_destroy(game_info);
		return (false);
	}
}

parser_t *parser_create(int ac, char **av)
{
	parser_t *game_info = NULL;

	if (ac < 12) {
		dprintf(2, "zappy_server: %sNot Enough Arguments\n",
			ANSI_BOLD_COLOR_RED"error : "ANSI_COLOR_RESET);
		return (NULL);
	}
	game_info = parser_alloc();
	if (!game_info)
		return (NULL);
	if (!parser_arg_handler(ac, av, game_info)) {
		parser_destroy(game_info);
		return (NULL);
	}
	if (parser_check(game_info))
		return (game_info);
	return (NULL);
}
