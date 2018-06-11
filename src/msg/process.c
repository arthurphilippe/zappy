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
#include "player.h"
#include "selector.h"
#include "stolist.h"

static void debug_list(list_t *list)
{
	list_iter_t *iter = list_iter_create(list, FWD);
	char *tmp;

	dprintf(2, "----------\ndebug list contents: %ld\n", list->l_size);
	if (!iter)
		return;
	while ((tmp = list_iter_next(iter)))
		dprintf(2, "%s\n", tmp);
	free(iter);
}

void msg_process(selector_t *stor, handle_t *hdl, const char *msg)
{
	list_t *split_msg = stolist(msg, " ");

	dprintf(2, "debug: processing %s\n", msg);
	if (!split_msg)
		return;
	debug_list(split_msg);
	if (hdl->h_type == H_PLAYER)
		msg_process_cmd_pl(stor, hdl, split_msg);
	else if (hdl->h_type == H_GFX) {
		// GFX PROCESSOR
	}
	list_destroy(split_msg);
}
