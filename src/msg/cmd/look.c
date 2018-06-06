/*
** EPITECH PROJECT, 2018
** PSU_zappy_2017
** File description:
** look
*/

#include <stdio.h>
#include "msg.h"
#include "player.h"
#include "dynbuf.h"

void msg_cmd_look(selector_t *stor, handle_t *hdl, list_t *args)
{
	dynbuf_t *buf = player_look(hdl->h_data, stor->s_data);

	(void) args;
	if (buf)
		dprintf(hdl->h_fd, "%s\n", buf->b_data);
}
