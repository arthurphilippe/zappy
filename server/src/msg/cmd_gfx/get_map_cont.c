/*
** EPITECH PROJECT, 2018
** server
** File description:
** get_map_cont
*/

#include <stdio.h>
#include "dynbuf.h"
#include "game.h"
#include "msg.h"

void msg_cmd_gfx_get_map_cont(selector_t *stor, handle_t *hdl, list_t *args)
{
	game_t *gm = stor->s_data;
	board_t *bd = gm->ga_board;
	dynbuf_t *buf = dynbuf_create();
	vector2d_t pos;

	(void) args;
	if (!buf)
		return;
	for (pos.v_y = 0; pos.v_y < (int) bd->b_max_y; pos.v_y++) {
		for (pos.v_x = 0; pos.v_x < (int) bd->b_max_y; pos.v_x++) {
			dynbuf_append_str(buf, "bct ");
			board_gfx_get_tile_cont(bd, buf, pos);
			dynbuf_append_str(buf, "\n");
		}
	}
	dprintf(hdl->h_fd, "%s", buf->b_data);
	dynbuf_delete(buf);
}
