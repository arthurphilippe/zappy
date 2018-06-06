/*
** EPITECH PROJECT, 2018
** zappy
** File description:
** parser_init
*/

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include "parser.h"

static bool body_set_struct_2(parser_t *game_info, int opt, const char *arg)
{
	switch (opt) {
	case 'p':
		game_info->port = atoi(arg);
		return (true);
		break;
	case 'x':
		game_info->width = atoi(arg);
		return (true);
		break;
	case 'y':
		game_info->height = atoi(arg);
		return (true);
		break;
	default:
		return (false);
		break;
	}
	return (false);

}

static bool body_set_struct(parser_t *game_info, int opt, const char *arg)
{
	if (!body_set_struct_2(game_info, opt, arg)) {
		switch (opt) {
		case 'c':
			game_info->client_nb = atoi(arg);
			return (true);
			break;
		case 'f':
			game_info->freq = atoi(arg);
			return (true);
			break;
		default:
			return (false);
			break;
		}
	}
	return (false);
}

bool parser_arg_handler(int ac, char **av, parser_t *game_info)
{
	int opt = 0;
	optind = 0;

	while ((opt = getopt(ac, av, "pxyncf")) != -1) {
		if (!body_set_struct(game_info, opt, av[optind]))
			switch (opt) {
			case 'n':
				while (optind < ac &&
					strncmp(av[optind], "-", 1)) {
					list_push_back(game_info->team_name,
							strdup(av[optind++]));
				}
				optind -= 1;
				break;
			case '?':
				return (false);
			default:
				break;
			}
	}
	return (true);
}

