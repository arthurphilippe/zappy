/*
** EPITECH PROJECT, 2018
** PSU_zappy_2017
** File description:
** client_get_msgq
*/

#include "selector.h"
#include "player.h"

list_t *client_get_msgq(handle_t *hdl)
{
	player_t *pl;

	if (hdl->h_type == H_PLAYER) {
		pl = hdl->h_data;
		return (pl->p_queued_msgs);
	} else if (hdl->h_type == H_GFX) {
		return (hdl->h_data);
	}
	return (NULL);
}
