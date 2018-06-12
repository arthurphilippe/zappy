/*
** EPITECH PROJECT, 2018
** PSU_zappy_2017
** File description:
** client_on_cycle
*/

#include <string.h>
#include "msg.h"
#include "player.h"
#include "selector.h"

/*
** What's to be done each time selector loops.
*/
void client_on_cycle(selector_t *stor, handle_t *hdl)
{
	list_t *msgq = client_get_msgq(hdl);
	handle_type_t old_type = hdl->h_type;

	if (msgq->l_size) {
		if (!strcasecmp("shutdown", msgq->l_start->n_data)) {
			stor->s_live = false;
			return;
		} else if (!strcasecmp("quit", msgq->l_start->n_data)) {
			client_erase(stor, hdl);
			return;
		}
		msg_process(stor, hdl, msgq->l_start->n_data);
		if (old_type == hdl->h_type)
			list_pop_front(msgq);
		else
			return;
	}
	if (!msgq->l_size)
		hdl->h_on_cycle = NULL;
}
