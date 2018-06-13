/*
** EPITECH PROJECT, 2018
** server
** File description:
** get_tile_cont
*/

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "dynbuf.h"
#include "game.h"
#include "msg.h"

static int extract_args(int *x, int *y, list_t *args)
{
	if (args->l_size < 2)
		return (-1);
	*x = atoi(args->l_start->n_data);
	*y = atoi(args->l_end->n_data);
	return (0);
}

static void print_qtes(game_t *gm, handle_t *hdl, int x, int y)
{
	dynbuf_t *buf = dynbuf_create();

	board_gfx_get_tile_cont(gm->ga_board, buf, (vector2d_t){x, y});
	dprintf(hdl->h_fd, ASW_TILE_CONT, buf->b_data);
	dynbuf_delete(buf);
}

void msg_cmd_gfx_get_tile_cont(selector_t *stor, handle_t *hdl, list_t *args)
{
	game_t *gm = stor->s_data;
	int pos_x;
	int pos_y;

	if (extract_args(&pos_x, &pos_y, args)) {
		dprintf(hdl->h_fd, ASW_BAD_PARAM);
	} else {
		print_qtes(gm, hdl, pos_x, pos_y);
	}
}
