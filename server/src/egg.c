/*
** EPITECH PROJECT, 2018
** PSU_zappy_2017
** File description:
** egg
*/

#include "egg.h"
#include <stdlib.h>
#include <string.h>
#include "chrono.h"
#include "get_wait_time.h"

egg_t *egg_create(const char *team, vector2d_t pos, unsigned int freq)
{
	static unsigned int id = 0;
	egg_t *egg = malloc(sizeof(egg_t));

	if (!egg)
		return (NULL);
	egg->eg_team_name = strdup(team);
	if (!egg->eg_team_name) {
		free(egg);
		return (NULL);
	}
	egg->eg_timer = chrono_create(get_wait_time(freq, 600));
	if (!egg->eg_timer) {
		free(egg->eg_team_name);
		free(egg);
		return (NULL);
	}
	egg->eg_pos = pos;
	egg->eg_id = ++id;
	return (egg);
}

void egg_delete(void *ptr)
{
	egg_t *egg = ptr;

	free(egg->eg_team_name);
	free(egg->eg_timer);
	free(egg);
}

bool egg_has_hatched(egg_t *egg)
{
	return (!egg->eg_timer ||
		chrono_check(egg->eg_timer) == CHRONO_EXPIRED);
}
