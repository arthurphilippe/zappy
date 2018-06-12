/*
** EPITECH PROJECT, 2018
** PSU_zappy_2017
** File description:
** inventory
*/

#include <stdio.h>
#include "msg.h"
#include "player.h"
#include "dynbuf.h"

void msg_cmd_pl_inventory(selector_t *stor, handle_t *hdl, list_t *args)
{
	dynbuf_t *buf = player_inventory_list(hdl->h_data);

	(void) args;
	(void) stor;
	if (buf)
		dprintf(hdl->h_fd, "%s\n", buf->b_data);
	dynbuf_delete(buf);
}
