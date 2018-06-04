/*
** EPITECH PROJECT, 2018
** zappy
** File description:
** parser_destroyer
*/

#include <stdlib.h>
#include "parser.h"

void parser_destroy(void *game_info)
{
	parser_t *tmp = (parser_t *) game_info;

	list_destroy(tmp->team_name);
	free(game_info);
}
