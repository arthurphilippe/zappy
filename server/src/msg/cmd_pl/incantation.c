/*
** EPITECH PROJECT, 2018
** server
** File description:
** incantation
*/

#include <stdio.h>
#include "msg.h"
#include "player.h"

void msg_cmd_pl_incentation(selector_t *stor, handle_t *hdl, list_t *args)
{
	player_t *pl = hdl->h_data;

	dprintf(hdl->h_fd, "Elevation underway Current level: %d", pl->p_lvl);
}
