/*
** EPITECH PROJECT, 2018
** PSU_zappy_2017
** File description:
** client_read
*/

#include <stdio.h>
#include <unistd.h>
#include "player.h"
#include "selector.h"
#include "stolist.h"

static void fill_gfx_queue(handle_t *hdl, const char *buf)
{
	list_t *msgq = client_get_msgq(hdl);

	stolist_existing(msgq, buf, "\r\n");
	if (msgq->l_size)
		hdl->h_on_cycle = client_on_cycle;
}

static void call_reader(handle_t *hdl, char *buf, int r)
{
	buf[r] = '\0';
	if (hdl->h_type == H_PLAYER) {
		client_player_buffer_process(hdl, buf);
	} else if (hdl->h_type == H_GFX) {
		fill_gfx_queue(hdl, buf);
	}
}

void client_read(selector_t *selector, handle_t *hdl)
{
	int r;
	char buf[512];

	r = read(hdl->h_fd, buf, 512);
	if (r > 0) {
		call_reader(hdl, buf, r);
	} else {
		client_erase(selector, hdl);
	}
}
