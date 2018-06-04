/*
** EPITECH PROJECT, 2018
** zappy
** File description:
** parser
*/

#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include "criterion/assert.h"
#include "criterion/criterion.h"
#include "parser.h"

Test(Parser, create)
{
	char **av = malloc(sizeof(char *) * 255);
	for (int i = 0; i < 255; i++) {
		av[i] = malloc(sizeof(char) * 255);
		memset(av[i], '\0', 255);
	}
	strcpy(av[0], "-p");
	strcpy(av[1], "70");
	strcpy(av[2], "-x");
	strcpy(av[3], "1280");
	strcpy(av[4], "-y");
	strcpy(av[5], "720");
	strcpy(av[6], "-n");
	strcpy(av[7], "Cameron");
	strcpy(av[8], "Kappa");
	strcpy(av[9], "Kawaii");
	strcpy(av[10], "Desuneeee ?");
	strcpy(av[11], "-c");
	strcpy(av[12], "11");
	strcpy(av[13], "-f");
	strcpy(av[14], "77");
	av[15] = NULL;
	int ac = 15;
	parser_t *parser = parser_create(ac, av);
	cr_assert(parser);
	for (int i = 0; i < 255; i++) {
		free(av[i]);
	}
	free(av);

}
