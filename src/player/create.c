/*
** EPITECH PROJECT, 2018
** PSU_zappy_2017
** File description:
** create
*/

#include <stdlib.h>
#include <string.h>
#include "player.h"

player_t *player_create(void)
{
	static int id = 1;
	player_t *pl = malloc(sizeof(player_t));

	if (!pl)
		return (NULL);
	pl->p_hostname = NULL;
	pl->p_teamname = NULL;
	pl->p_id = id++;
	return (pl);
}
