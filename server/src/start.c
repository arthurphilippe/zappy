/*
** EPITECH PROJECT, 2018
** PSU_zappy_2017
** File description:
** start
*/

#include <stdio.h>
#include "game.h"
#include "parser.h"
#include "selector.h"

/*
** Adds the teams specified in the parser to the game.
*/
static void add_teams(game_t *gm, list_t *teams)
{
	while (teams->l_size) {
		game_add_team(gm, list_get_front(teams));
		list_pop_front(teams);
	}
}

/*
** Prepares the selector for the game
*/
static int bstrap_stor(selector_t **stor, parser_t *parser)
{
	*stor = selector_create();
	if (!(*stor))
		return (84);
	(*stor)->s_data = game_create(parser->width, parser->height,
		parser->freq, parser->client_nb);
	if (!(*stor)->s_data) {
		selector_delete((*stor));
		return (84);
	}
	(*stor)->s_delete = game_delete;
	(*stor)->s_on_cycle = game_on_cycle;
	add_teams((*stor)->s_data, parser->team_name);
	if (listener_create((*stor), parser->port)) {
		perror("listener");
		selector_delete((*stor));
		return (84);
	}
	return (0);
}

/*
** prepares and run the selector for the game
*/
int start(parser_t *parser)
{
	selector_t *stor;
	int ret = bstrap_stor(&stor, parser);

	if (ret)
		return (ret);
	selector_loop(stor);
	parser_destroy(parser);
	selector_delete(stor);
	return (0);
}
