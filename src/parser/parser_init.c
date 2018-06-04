/*
** EPITECH PROJECT, 2018
** zappy
** File description:
** parser_init
*/

#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include "parser.h"

void parser_arg_handler(int ac, char **av, parser_t *game_info)
{
	int opt = 0;
	optind = 0;

	while ((opt = getopt(ac, av, "pxyncf")) != -1) {
		switch (opt) {
		case 'p':
			game_info->port = atoi(av[optind]);
			break;
		case 'x':
			game_info->width = atoi(av[optind]);
			break;
		case 'y':
			game_info->height = atoi(av[optind]);
			break;
		case 'n':
			while (optind < ac && strncmp(av[optind], "-", 1)) {
				list_push_back(game_info->team_name,
						strdup(av[optind++]));
			}
			optind -= 1;
			break;
		case 'c':
			game_info->client_nb = atoi(av[optind]);
			break;
		case 'f':
			game_info->freq = atoi(av[optind]);
			break;
		default:
			break;
		}
	}
}

parser_t *parser_alloc()
{
	parser_t *game_info = malloc(sizeof(parser_t));

	if (!game_info)
		return (NULL);
	memset(game_info, 0, sizeof(parser_t));
	game_info->team_name = list_create((free));
	return (game_info);
}
