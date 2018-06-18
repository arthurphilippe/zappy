/*
** EPITECH PROJECT, 2018
** server
** File description:
** lifespan_check
*/

#include <string.h>
#include <stdio.h>
#include "player.h"
#include "selector.h"

void kill_player(selector_t *stor, handle_t *hdl, list_t *args)
{
	player_t *pl = hdl->h_data;

	(void) args;
	(void) stor;
	dprintf(hdl->h_fd, "dead\n");
	list_push_back(pl->p_queued_msgs, strdup("quit"));
}

void player_lifespan_check(player_t *pl)
{
	if (chrono_check(&pl->p_lifespan) == CHRONO_EXPIRED &&
		!pl->p_inventory[FOOD]) {
		list_push_back(pl->p_queued_msgs, strdup("quit"));
	} else if (chrono_check(&pl->p_lifespan) == CHRONO_EXPIRED) {
		pl->p_inventory[FOOD] -= 1;
		chrono_init(&pl->p_lifespan, LIFE_EXPECTANCY);
	}
}