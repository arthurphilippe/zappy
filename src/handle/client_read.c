/*
** EPITECH PROJECT, 2018
** PSU_zappy_2017
** File description:
** client_read
*/

#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include "selector.h"
#include "stolist.h"
#include "player.h"

static void trucate_queue(list_t *list)
{
	while (list_get_size(list) > 10)
		list_pop_back(list);
}

static void fill_player_queue(player_t *pl, const char *buf)
{
	if (!pl)
		return;
	stolist_existing(pl->p_queued_msgs, buf, "\r\n");
	trucate_queue(pl->p_queued_msgs);
}

void client_read(selector_t *selector, handle_t *hdl)
{
	int r;
	char buf[512];

	r = read(hdl->h_fd, buf, 512);
	if (r > 0) {
		buf[r] = '\0';
		printf("%d: %s\n", hdl->h_fd, buf);
		if (!strncmp("QUIT", buf, 4))
			client_delete(selector, hdl);
		else
			fill_player_queue(hdl->h_data, buf);
	} else {
		client_delete(selector, hdl);
	}
}
