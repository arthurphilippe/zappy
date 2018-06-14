/*
** EPITECH PROJECT, 2018
** server
** File description:
** on_cycle
*/

#include <string.h>
#include "stolist.h"
#include "player.h"
#include "msg.h"
#include "selector.h"

static void trucate_queue(list_t *list)
{
	while (list_get_size(list) > 10)
		list_pop_back(list);
}

static void split_and_process(selector_t *stor, handle_t *hdl, const char *msg)
{
	list_t *split_msg = stolist(msg, " ");

	if (!split_msg)
		return;
	msg_process_cmd_pl(stor, hdl, split_msg);
	list_destroy(split_msg);
}

void player_on_cycle(selector_t *stor, handle_t *hdl)
{
	player_t *pl = hdl->h_data;
	list_t *msgq = pl->p_queued_msgs;
	handle_type_t old_type = hdl->h_type;

	if (msgq->l_size) {
		if (!strcasecmp("shutdown", msgq->l_start->n_data)) {
			stor->s_live = false;
			return;
		} else if (!strcasecmp("quit", msgq->l_start->n_data)) {
			client_erase(stor, hdl);
			return;
		}
		trucate_queue(msgq);
		split_and_process(stor, hdl, msgq->l_start->n_data);
		if (old_type == hdl->h_type)
			list_pop_front(msgq);
		else
			return;
	}
	if (!msgq->l_size)
		hdl->h_on_cycle = NULL;
}
