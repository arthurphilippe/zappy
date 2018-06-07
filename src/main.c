/*
** EPITECH PROJECT, 2018
** PSU_zappy_2017
** File description:
** main
*/

#include <stdio.h>
#include "parser.h"
#include "start.h"

static void print_usage_server(const char *bin)
{
	printf("\nUSAGE: %s %s\n", bin,
		"-p port -x width -y height -n name1"
		" name2 ... -c clientsNb -f freq\n\tport\t\tis the port "
		"number\n\twidth\t\tis the width of the world\n"
		"\theight\t\tis the height of the world\n"
		"\tnameX\t\tis the name of the team X\n"
		"\tclientsNb\tis the number of authorized clients per team\n"
		"\tfreq\t\tis the reciprocal of time unit for execution of "
		"action");
}

int main(int ac, char **av)
{
	int ret;
	parser_t *parser = parser_create(ac, av);

	if (parser) {
		ret = start(parser);
	} else {
		print_usage_server(av[0]);
		ret = 84;
	}
	if (ret)
		parser_destroy(parser);
	return (ret);
}
