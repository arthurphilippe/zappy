/*
** EPITECH PROJECT, 2018
** server
** File description:
** on_cycle
*/

#include <string.h>
#include "stolist.h"
#include "selector.h"
#include "msg.h"

static void split_and_process(selector_t *stor, handle_t *hdl, const char *msg)
{
	list_t *split_msg = stolist(msg, " ");

	if (!split_msg)
		return;
	msg_process_cmd_gfx(stor, hdl, split_msg);
	list_destroy(split_msg);
}

void gfx_on_cycle(selector_t *stor, handle_t *hdl)
{
	list_t *msgq = hdl->h_data;

	if (msgq->l_size) {
		if (!strcasecmp("shutdown", msgq->l_start->n_data)) {
			stor->s_live = false;
		} else if (!strcasecmp("quit", msgq->l_start->n_data)) {
			client_erase(stor, hdl);
		} else {
			split_and_process(stor, hdl, msgq->l_start->n_data);
			list_pop_front(msgq);
		}
	}
	if (!msgq->l_size)
		hdl->h_on_cycle = NULL;
}
