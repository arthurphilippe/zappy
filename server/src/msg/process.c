/*
** EPITECH PROJECT, 2018
** PSU_zappy_2017
** File description:
** process
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "msg.h"
#include "msg_cmd_pl.h"
#include "player.h"
#include "selector.h"
#include "stolist.h"

void msg_process(selector_t *stor, handle_t *hdl, const char *msg)
{
	list_t *split_msg = stolist(msg, " ");

	if (!split_msg)
		return;
	if (hdl->h_type == H_PLAYER)
		msg_process_cmd_pl(stor, hdl, split_msg);
	else if (hdl->h_type == H_GFX) {
		msg_process_cmd_gfx(stor, hdl, split_msg);
	}
	list_destroy(split_msg);
}
