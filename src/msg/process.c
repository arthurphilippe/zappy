/*
** EPITECH PROJECT, 2018
** PSU_zappy_2017
** File description:
** process
*/

#include <stdio.h>
#include <stdlib.h>
#include "selector.h"
#include "stolist.h"
#include "msg.h"
#include "player.h"

const msg_map_t MSG_CMD_MAP[] = {
	{NULL, NULL},
};

static void debug_list(list_t *list)
{
	list_iter_t *iter = list_iter_create(list, FWD);
	char *tmp;

	dprintf(2, "----------\ndebug list contents: %ld\n", list->l_size);
	if (!iter)
		return;
	while ((tmp = list_iter_next(iter))) {
		dprintf(2, "%s\n", tmp);
	}
	free(iter);
}

void msg_process(selector_t *stor, handle_t *hdl, const char *msg)
{
	list_t *split_msg = stolist(msg, " ");
	player_t *pl = hdl->h_data;

	(void) stor;
	dprintf(2, "debug: processing %s\n", msg);
	if (!split_msg)
		return;
	debug_list(split_msg);
	if (!pl->p_teamname && split_msg->l_size)
		msg_join(stor, hdl, pl, split_msg->l_start->n_data);
	list_destroy(split_msg);
}
