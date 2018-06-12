/*
** EPITECH PROJECT, 2018
** zappy
** File description:
** parser
*/

#ifndef PARSER_H_
	#define PARSER_H_

	#include "stolist.h"

typedef struct	s_parser {
	list_t	*team_name;
	int	port;
	int	width;
	int	height;
	int	client_nb;
	int	freq;
}		parser_t;

/*
** This is used to destroy "team_name list"
*/
void parser_destroy(void *game_info);

/*
** Create a new struct with the game information passed as arg
*/
parser_t *parser_create(int ac, char **av);

/*
** Parse the args
*/
bool parser_arg_handler(int ac, char **av, parser_t *game_info);

#endif /* !PARSER_H_ */
