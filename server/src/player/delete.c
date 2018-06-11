/*
** EPITECH PROJECT, 2018
** PSU_zappy_2017
** File description:
** delete
*/

#include <stdlib.h>
#include "player.h"

void player_delete(void *ptr)
{
	player_t *pl = ptr;

	free(pl->p_teamname);
	list_destroy(pl->p_queued_msgs);
	free(pl);
}
