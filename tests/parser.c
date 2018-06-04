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
	strcpy(av[1], "-p");
	strcpy(av[2], "70");
	strcpy(av[3], "-x");
	strcpy(av[4], "1280");
	strcpy(av[5], "-y");
	strcpy(av[6], "720");
	strcpy(av[7], "-n");
	strcpy(av[8], "Cameron");
	strcpy(av[9], "Kappa");
	strcpy(av[10], "Kawaii");
	strcpy(av[11], "Desuneeee ?");
	strcpy(av[12], "-c");
	strcpy(av[13], "11");
	strcpy(av[14], "-f");
	strcpy(av[15], "77");
	av[16] = NULL;
	int ac = 15;
	parser_t *parser = parser_create(ac, av);
	cr_assert(parser);
	for (int i = 0; i < 255; i++) {
		free(av[i]);
	}
	free(av);

}
