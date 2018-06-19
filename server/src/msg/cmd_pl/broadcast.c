/*
** EPITECH PROJECT, 2018
** PSU_zappy_2017
** File description:
** broadcast
*/

#include <stdio.h>
#include "broadcast.h"
#include "dynbuf.h"
#include "game.h"
#include "msg.h"
#include "player.h"

static void notify_all_players(
	selector_t *stor, player_t *pl, const char *msg)
{
	list_iter_t iter;
	handle_t *hdl;
	player_t *tmp_pl;
	int tile;

	list_iter_init(&iter, stor->s_handles, FWD);
	while ((hdl = list_iter_next(&iter))) {
		if (hdl->h_type == H_PLAYER) {
			tmp_pl = hdl->h_data;
			tile = broacast_get_prior_tile(
				pl->p_pos, tmp_pl->p_pos, tmp_pl->p_dir);
			dprintf(hdl->h_fd, "message %d%s\n", tile, msg);
		}
	}
}

static dynbuf_t *create_msg(list_t *args)
{
	list_iter_t iter;
	dynbuf_t *buf = dynbuf_create();
	char *tmp;

	if (!buf)
		return (NULL);
	list_iter_init(&iter, args, FWD);
	while ((tmp = list_iter_next(&iter))) {
		dynbuf_append_str(buf, " ");
		dynbuf_append_str(buf, tmp);
	}
	return (buf);
}

void msg_cmd_pl_boradcast(selector_t *stor, handle_t *hdl, list_t *args)
{
	dynbuf_t *buf = create_msg(args);

	if (buf) {
		notify_all_players(stor, hdl->h_data, buf->b_data);
		dynbuf_delete(buf);
	}
	dprintf(hdl->h_fd, "ok\n");
}
