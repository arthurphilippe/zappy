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
	player_t *pl = calloc(1, sizeof(player_t));
	static int id = 1;

	if (!pl)
		return (NULL);
	pl->p_teamname = NULL;
	pl->p_queued_msgs = list_create(free);
	pl->p_id = id++;
	pl->p_pos = (vector2d_t){0, 0};
	pl->p_dir = (vector2d_t){1, 0};
	pl->p_lvl = 1;
	return (pl);
}

player_t *player_create_at(vector2d_t pos)
{
	player_t *pl = player_create();

	if (pl)
		pl->p_pos = pos;
	return (pl);
}
