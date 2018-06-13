/*
** EPITECH PROJECT, 2018
** server
** File description:
** get_team_names
*/

#include <stdio.h>
#include "dynbuf.h"
#include "game.h"
#include "msg.h"
#include "team.h"

void msg_cmd_gfx_get_team_names(selector_t *stor, handle_t *hdl, list_t *args)
{
	game_t *gm = stor->s_data;
	dynbuf_t *buf = dynbuf_create();
	list_iter_t it;
	team_t *tm;

	(void) args;
	if (!buf)
		return;
	for (list_iter_init(&it, gm->ga_teams, FWD);
		(tm = list_iter_access(&it)); list_iter_next(&it)) {
		dynbuf_append_str(buf, "tna ");
		dynbuf_append_str(buf, tm->t_name);
		dynbuf_append_str(buf, "\n");
	}
	dprintf(hdl->h_fd, "%s", buf->b_data);
	dynbuf_delete(buf);
}
