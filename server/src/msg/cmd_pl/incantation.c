/*
** EPITECH PROJECT, 2018
** server
** File description:
** incantation
*/

#include <stdio.h>
#include "msg.h"
#include "player.h"
#include "player_rite.h"

void msg_cmd_pl_incentation_callback(
	selector_t *stor, handle_t *hdl, list_t *args)
{
	player_t *pl = hdl->h_data;

	(void) stor;
	(void) args;
	pl->p_lvl += 1;
}

void msg_cmd_pl_incentation(selector_t *stor, handle_t *hdl, list_t *args)
{
	player_t *pl = hdl->h_data;

	(void) args;
	if (player_rite_check_tile(pl, stor->s_data)) {
		dprintf(hdl->h_fd, "Elevation underway Current level: %d\n",
			pl->p_lvl);
		pl->p_task.dc_callback = msg_cmd_pl_incentation_callback;
		chrono_init(&pl->p_task.dc_timer, 300);
	}
	else
		dprintf(hdl->h_fd, "ko\n");
}
