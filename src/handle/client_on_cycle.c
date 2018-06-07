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
** This is where a time delay will be requiered.
*/
void client_on_cycle(selector_t *stor, handle_t *hdl)
{
	player_t *pl = hdl->h_data;

	if (pl->p_queued_msgs->l_size) {
		if (!strcasecmp(
			"shutown", pl->p_queued_msgs->l_start->n_data)) {
			stor->s_live = false;
			return;
		} else if (!strcasecmp("quit",
				pl->p_queued_msgs->l_start->n_data)) {
			client_delete(stor, hdl);
			return;
		}
		msg_process(stor, hdl, pl->p_queued_msgs->l_start->n_data);
		list_pop_front(pl->p_queued_msgs);
	}
}
