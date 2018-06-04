/*
** EPITECH PROJECT, 2018
** zappy
** File description:
** parser
*/

#include <stdbool.h>
#include "parser.h"

static bool parser_check(parser_t *game_info)
{
	if ((game_info->client_nb) && (game_info->freq) && (game_info->height)
		&& (game_info->port) && list_get_size(game_info->team_name) &&
		(game_info->width))
		return (true);
	else
		return (false);
}

parser_t *parser_create(int ac, char **av)
{
	parser_t *game_info = parser_alloc();

	if (!game_info)
		return (NULL);
	parser_arg_handler(ac, av, game_info);
	if (parser_check(game_info))
		return (game_info);
	return (NULL);
}
