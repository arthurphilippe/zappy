/*
** EPITECH PROJECT, 2018
** PSU_zappy_2017
** File description:
** main
*/

#include "parser.h"
#include "start.h"

int main(int ac, char **av)
{
	int ret;
	parser_t *parser = parser_create(ac, av);

	if (parser) {
		ret = start(parser);
		parser_destroy(parser);
	} else {
		ret = 84;
	}
	return (ret);
}

// int main(int ac, char **av)
// {
// 	int ret;

// 	if (ac >= 2)
// 		ret = start_game_tmp(atoi(av[1]));
// 	else
// 		ret = 84;
// 	return (ret);
// }
