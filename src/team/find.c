/*
** EPITECH PROJECT, 2018
** PSU_zappy_2017
** File description:
** find
*/

#include <stdlib.h>
#include <string.h>
#include "team.h"

team_t *team_find_by_name(list_t *teams, const char *name)
{
	list_iter_t *iter = list_iter_create(teams, FWD);
	team_t *team;
	team_t *ret = NULL;

	if (!iter)
		return (NULL);
	while ((team = list_iter_next(iter)) && !ret) {
		if (!strcmp(name, team->t_name))
			ret = team;
	}
	free(iter);
	return (ret);
}
