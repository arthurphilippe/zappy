/*
** EPITECH PROJECT, 2018
** PSU_zappy_2017
** File description:
** create
*/

#include <stdlib.h>
#include <string.h>
#include "player.h"

player_t *player_create(const char *team_name, const char *hostname)
{
	static int id = 1;
	player_t *pl = malloc(sizeof(player_t));

	if (!pl)
		return (NULL);
	pl->p_teamname = strdup(team_name);
	if (!pl->p_teamname) {
		free(pl);
		return (NULL);
	}
	pl->p_hostname = strdup(hostname);
	if (!pl->p_hostname) {
		free(pl->p_teamname);
		free(pl);
		return (NULL);
	}
	pl->p_id = id++;
	return (pl);
}
