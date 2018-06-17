/*
** EPITECH PROJECT, 2018
** server
** File description:
** lifespan_check
*/

#include <stdio.h>
#include "player.h"
#include "selector.h"

void kill_player(selector_t *stor, handle_t *hdl, list_t *args)
{
	(void) args;
	(void) stor;
	dprintf(hdl->h_fd, "dead\n");
	client_erase(stor, hdl);
}

void player_lifespan_check(player_t *pl)
{
	if (chrono_check(&pl->p_lifespan) == CHRONO_EXPIRED &&
		!pl->p_inventory[FOOD]) {
		pl->p_task.dc_callback = kill_player;
		pl->p_task.dc_args = NULL;
		chrono_init(&pl->p_task.dc_timer, 0);
	} else if (chrono_check(&pl->p_lifespan) == CHRONO_EXPIRED) {
		pl->p_inventory[FOOD] -= 1;
		chrono_init(&pl->p_lifespan, LIFE_EXPECTANCY);
	}
}
