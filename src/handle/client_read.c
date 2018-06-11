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

static void call_reader(handle_t *hdl, char *buf, int r)
{
	if (hdl->h_type == H_PLAYER) {
		client_player_buffer_process(hdl, buf, r);
	} else if (hdl->h_type == H_GFX) {
		// TODO: add gfx reader call
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
