/*
** EPITECH PROJECT, 2018
** server
** File description:
** on_cycle
*/

#include <string.h>
#include "chrono.h"
#include "msg.h"
#include "player.h"
#include "selector.h"
#include "stolist.h"

static void trucate_queue(list_t *list)
{
	while (list_get_size(list) > 10)
		list_pop_back(list);
}

static bool split_and_process(
	selector_t *stor, handle_t *hdl, const char *msg)
{
	list_t *split_msg = stolist(msg, " ");
	bool ret = false;

	if (!split_msg)
		return ret;
	ret = msg_process_cmd_pl(stor, hdl, split_msg);
	list_destroy(split_msg);
	return (ret);
}

static bool ingest_msg(selector_t *stor, handle_t *hdl, list_t *msgq)
{
	handle_type_t old_type = hdl->h_type;
	bool ret;

	if (msgq->l_size) {
		trucate_queue(msgq);
		ret = split_and_process(stor, hdl, msgq->l_start->n_data);
		if (ret && old_type == hdl->h_type)
			list_pop_front(msgq);
		if (old_type != hdl->h_type)
			return (false);
	}
	return (true);
}

static bool halt_checker(selector_t *stor, handle_t *hdl, list_t *msgq)
{
	list_iter_t iter;
	const char *tmp;

	list_iter_init(&iter, msgq, FWD);
	while ((tmp = list_iter_next(&iter))) {
		if (!strcasecmp("shutdown", tmp)) {
			stor->s_live = false;
			return (true);
		} else if (!strcasecmp("quit", tmp)) {
			client_erase(stor, hdl);
			return (true);
		}
	}
	return (false);
}

/*
** player routine to call on each cycle.
** - if the player quit or shutown is recived the function imidiatly returns.
** - if a callback is set and the task timer expired, the task is executed
** . and reset.
** - afterwards, if no callback is set, the functions tries to ingest
** . a command. if no special case occured, the function checks if
** . there is something to do on next cycle or not.
*/
void player_on_cycle(selector_t *stor, handle_t *hdl)
{
	player_t *pl = hdl->h_data;
	list_t *msgq = pl->p_queued_msgs;

	if (halt_checker(stor, hdl, msgq))
		return;
	if (pl->p_task.dc_callback &&
		chrono_check(&pl->p_task.dc_timer) == CHRONO_EXPIRED) {
		pl->p_task.dc_callback(stor, hdl, pl->p_task.dc_args);
		pl->p_task.dc_callback = NULL;
		pl->p_task.dc_args = NULL;
		list_pop_front(msgq);
	}
	if (!pl->p_task.dc_callback && ingest_msg(stor, hdl, msgq) &&
		!msgq->l_size && !pl->p_task.dc_callback) {
		hdl->h_on_cycle = NULL;
	}
}
