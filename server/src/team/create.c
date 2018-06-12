/*
** EPITECH PROJECT, 2018
** PSU_zappy_2017
** File description:
** create
*/

#include <stdlib.h>
#include <string.h>
#include "team.h"

team_t *team_create(const char *name, unsigned int max_memb)
{
	team_t *tm = malloc(sizeof(team_t));

	if (!tm)
		return (NULL);
	tm->t_name = strdup(name);
	if (!tm->t_name) {
		free(tm);
		return (NULL);
	}
	tm->t_membs = list_create(NULL);
	if (!tm->t_membs) {
		free(tm->t_name);
		free(tm);
		return (NULL);
	}
	tm->t_max_memb = max_memb;
	return (tm);
}
