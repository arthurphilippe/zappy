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
#include "gfx.h"

static list_t *client_get_msgq(handle_t *hdl)
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

static void fill_queue(handle_t *hdl, const char *buf)
{
	list_t *msgq = client_get_msgq(hdl);

	if (msgq) {
		stolist_existing(msgq, buf, "\r\n");
		if (msgq->l_size && hdl->h_type == H_PLAYER)
			hdl->h_on_cycle = player_on_cycle;
		else if (msgq->l_size && hdl->h_type == H_GFX)
			hdl->h_on_cycle = gfx_on_cycle;
	}
}

/*
** Call the buffer processor that corresponds to the client.
*/
static void call_reader(handle_t *hdl, char *buf, int r)
{
	buf[r] = '\0';
	fill_queue(hdl, buf);
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
