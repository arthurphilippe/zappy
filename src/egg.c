/*
** EPITECH PROJECT, 2018
** PSU_zappy_2017
** File description:
** egg
*/

#include <stdlib.h>
#include <string.h>
#include "egg.h"

// TODO: use a tiemr!
egg_t *egg_create(const char *team, vector2d_t pos)
{
	egg_t *egg = malloc(sizeof(egg_t));

	egg->eg_team_name = strdup(team);
	egg->eg_timer = NULL;
	egg->eg_pos = pos;
}

void egg_delete(void *ptr)
{
	egg_t *egg = ptr;

	free(egg->eg_team_name);
	free(egg);
}
