/*
** EPITECH PROJECT, 2018
** PSU_zappy_2017
** File description:
** read
*/

#include <stdio.h>
#include <unistd.h>
#include "player.h"
#include "selector.h"
#include "stolist.h"

static void trucate_queue(list_t *list)
{
	while (list_get_size(list) > 10)
		list_pop_back(list);
}

size_t player_fill_queue(player_t *pl, const char *buf)
{
	if (!pl)
		return (0);
	stolist_existing(pl->p_queued_msgs, buf, "\r\n");
	trucate_queue(pl->p_queued_msgs);
	return (pl->p_queued_msgs->l_size);
}

void client_player_buffer_process(handle_t *hdl, char *buf)
{
	printf("recived from %d: %s\n", hdl->h_fd, buf);
	player_fill_queue(hdl->h_data, buf);
}
