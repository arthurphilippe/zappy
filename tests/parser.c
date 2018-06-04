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
	strcpy(av[0], "zappy_server");
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
	cr_assert(parser->client_nb == 11);
	cr_assert(parser->freq == 77);
	cr_assert(parser->port == 70);
	cr_assert(parser->width == 1280);
	cr_assert(parser->height == 720);
	cr_assert(list_get_size(parser->team_name) == 4);
	for (int i = 0; i < 255; i++) {
		free(av[i]);
	}
	free(av);
}

Test(Parser, port_only)
{
	char **av = malloc(sizeof(char *) * 255);
	for (int i = 0; i < 255; i++) {
		av[i] = malloc(sizeof(char) * 255);
		memset(av[i], '\0', 255);
	}
	strcpy(av[0], "zappy_server");
	strcpy(av[1], "-p");
	strcpy(av[2], "70");
	av[3] = NULL;
	int ac = 2;
	parser_t *parser = parser_create(ac, av);
	cr_assert_eq(parser, NULL);
	for (int i = 0; i < 255; i++) {
		free(av[i]);
	}
	free(av);
}

Test(Parser, port_0)
{
	char **av = malloc(sizeof(char *) * 255);
	for (int i = 0; i < 255; i++) {
		av[i] = malloc(sizeof(char) * 255);
		memset(av[i], '\0', 255);
	}
	strcpy(av[0], "zappy_server");
	strcpy(av[1], "-p");
	av[1] = NULL;
	int ac = 1;
	parser_t *parser = parser_create(ac, av);
	cr_assert_eq(parser, NULL);
	for (int i = 0; i < 255; i++) {
		free(av[i]);
	}
	free(av);
}

Test(Parser, width_only)
{
	char **av = malloc(sizeof(char *) * 255);
	for (int i = 0; i < 255; i++) {
		av[i] = malloc(sizeof(char) * 255);
		memset(av[i], '\0', 255);
	}
	strcpy(av[0], "zappy_server");
	strcpy(av[1], "-x");
	strcpy(av[2], "70");
	av[3] = NULL;
	int ac = 2;
	parser_t *parser = parser_create(ac, av);
	cr_assert_eq(parser, NULL);
	for (int i = 0; i < 255; i++) {
		free(av[i]);
	}
	free(av);
}

Test(Parser, width_0)
{
	char **av = malloc(sizeof(char *) * 255);
	for (int i = 0; i < 255; i++) {
		av[i] = malloc(sizeof(char) * 255);
		memset(av[i], '\0', 255);
	}
	strcpy(av[0], "zappy_server");
	strcpy(av[1], "-x");
	av[1] = NULL;
	int ac = 1;
	parser_t *parser = parser_create(ac, av);
	cr_assert_eq(parser, NULL);
	for (int i = 0; i < 255; i++) {
		free(av[i]);
	}
	free(av);
}

Test(Parser, height_only)
{
	char **av = malloc(sizeof(char *) * 255);
	for (int i = 0; i < 255; i++) {
		av[i] = malloc(sizeof(char) * 255);
		memset(av[i], '\0', 255);
	}
	strcpy(av[0], "zappy_server");
	strcpy(av[1], "-y");
	strcpy(av[2], "70");
	av[3] = NULL;
	int ac = 2;
	parser_t *parser = parser_create(ac, av);
	cr_assert_eq(parser, NULL);
	for (int i = 0; i < 255; i++) {
		free(av[i]);
	}
	free(av);
}

Test(Parser, height_0)
{
	char **av = malloc(sizeof(char *) * 255);
	for (int i = 0; i < 255; i++) {
		av[i] = malloc(sizeof(char) * 255);
		memset(av[i], '\0', 255);
	}
	strcpy(av[0], "zappy_server");
	strcpy(av[1], "-y");
	av[1] = NULL;
	int ac = 1;
	parser_t *parser = parser_create(ac, av);
	cr_assert_eq(parser, NULL);
	for (int i = 0; i < 255; i++) {
		free(av[i]);
	}
	free(av);
}

Test(Parser, clientnb_only)
{
	char **av = malloc(sizeof(char *) * 255);
	for (int i = 0; i < 255; i++) {
		av[i] = malloc(sizeof(char) * 255);
		memset(av[i], '\0', 255);
	}
	strcpy(av[0], "zappy_server");
	strcpy(av[1], "-c");
	strcpy(av[2], "70");
	av[3] = NULL;
	int ac = 2;
	parser_t *parser = parser_create(ac, av);
	cr_assert_eq(parser, NULL);
	for (int i = 0; i < 255; i++) {
		free(av[i]);
	}
	free(av);
}

Test(Parser, clientnb_0)
{
	char **av = malloc(sizeof(char *) * 255);
	for (int i = 0; i < 255; i++) {
		av[i] = malloc(sizeof(char) * 255);
		memset(av[i], '\0', 255);
	}
	strcpy(av[0], "zappy_server");
	strcpy(av[1], "-c");
	av[1] = NULL;
	int ac = 1;
	parser_t *parser = parser_create(ac, av);
	cr_assert_eq(parser, NULL);
	for (int i = 0; i < 255; i++) {
		free(av[i]);
	}
	free(av);
}


Test(Parser, freq_only)
{
	char **av = malloc(sizeof(char *) * 255);
	for (int i = 0; i < 255; i++) {
		av[i] = malloc(sizeof(char) * 255);
		memset(av[i], '\0', 255);
	}
	strcpy(av[0], "zappy_server");
	strcpy(av[1], "-f");
	strcpy(av[2], "70");
	av[3] = NULL;
	int ac = 2;
	parser_t *parser = parser_create(ac, av);
	cr_assert_eq(parser, NULL);
	for (int i = 0; i < 255; i++) {
		free(av[i]);
	}
	free(av);
}

Test(Parser, freq_0)
{
	char **av = malloc(sizeof(char *) * 255);
	for (int i = 0; i < 255; i++) {
		av[i] = malloc(sizeof(char) * 255);
		memset(av[i], '\0', 255);
	}
	strcpy(av[0], "zappy_server");
	strcpy(av[1], "-f");
	av[1] = NULL;
	int ac = 1;
	parser_t *parser = parser_create(ac, av);
	cr_assert_eq(parser, NULL);
	for (int i = 0; i < 255; i++) {
		free(av[i]);
	}
	free(av);
}


Test(Parser, team_name_only)
{
	char **av = malloc(sizeof(char *) * 255);
	for (int i = 0; i < 255; i++) {
		av[i] = malloc(sizeof(char) * 255);
		memset(av[i], '\0', 255);
	}
	strcpy(av[0], "zappy_server");
	strcpy(av[1], "-n");
	strcpy(av[2], "70");
	av[3] = NULL;
	int ac = 2;
	parser_t *parser = parser_create(ac, av);
	cr_assert_eq(parser, NULL);
	for (int i = 0; i < 255; i++) {
		free(av[i]);
	}
	free(av);
}

Test(Parser, team_name_0)
{
	char **av = malloc(sizeof(char *) * 255);
	for (int i = 0; i < 255; i++) {
		av[i] = malloc(sizeof(char) * 255);
		memset(av[i], '\0', 255);
	}
	strcpy(av[0], "zappy_server");
	strcpy(av[1], "-n");
	av[1] = NULL;
	int ac = 1;
	parser_t *parser = parser_create(ac, av);
	cr_assert_eq(parser, NULL);
	for (int i = 0; i < 255; i++) {
		free(av[i]);
	}
	free(av);
}

Test(Parser, create_portneg)
{
	char **av = malloc(sizeof(char *) * 255);
	for (int i = 0; i < 255; i++) {
		av[i] = malloc(sizeof(char) * 255);
		memset(av[i], '\0', 255);
	}
	strcpy(av[0], "zappy_server");
	strcpy(av[1], "-p");
	strcpy(av[2], "-1");
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
	cr_assert(!parser);
	for (int i = 0; i < 255; i++) {
		free(av[i]);
	}
	free(av);
}
