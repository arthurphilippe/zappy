/*
** EPITECH PROJECT, 2018
** PSU_zappy_2017
** File description:
** broadcast
*/

#include <stdio.h>
#include "game.h"
#include "msg.h"
#include "player.h"

void msg_cmd_pl_boradcast(selector_t *stor, handle_t *hdl, list_t *args)
{
	dprintf(hdl->h_fd, "ok\n");
	(void) stor;
	(void) args;
}
