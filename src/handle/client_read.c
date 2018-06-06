/*
** EPITECH PROJECT, 2018
** PSU_zappy_2017
** File description:
** client_read
*/

#include <stdio.h>
#include <unistd.h>
#include "selector.h"
#include "stolist.h"
#include "player.h"

static void trucate_queue(list_t *list)
{
	while (list_get_size(list) > 10)
		list_pop_back(list);
}

void client_fill_player_queue(player_t *pl, const char *buf)
{
	if (!pl)
		return;
	stolist_existing(pl->p_queued_msgs, buf, "\r\n");
	trucate_queue(pl->p_queued_msgs);
}

static void client_buffer_process(handle_t *hdl,
				char *buf, int r_size)
{
	buf[r_size] = '\0';
	printf("recived from %d: %s\n", hdl->h_fd, buf);
	client_fill_player_queue(hdl->h_data, buf);
}

void client_read(selector_t *selector, handle_t *hdl)
{
	int r;
	char buf[512];

	r = read(hdl->h_fd, buf, 512);
	if (r > 0) {
		client_buffer_process(hdl, buf, r);
	} else {
		client_delete(selector, hdl);
	}
}
