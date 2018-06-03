/*
** EPITECH PROJECT, 2018
** PSU_zappy_2017
** File description:
** client_on_cycle
*/

#include "selector.h"
#include "player.h"
#include "msg.h"

/*
** This is where a time delay will be requiered.
*/
void client_on_cycle(selector_t *stor, handle_t *hdl)
{
	player_t *pl = hdl->h_data;

	if (pl->p_queued_msgs->l_size) {
		msg_process(stor, hdl, pl->p_queued_msgs->l_start->n_data);
		list_pop_front(pl->p_queued_msgs);
	}
}
