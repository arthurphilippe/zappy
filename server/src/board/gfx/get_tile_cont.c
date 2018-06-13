/*
** EPITECH PROJECT, 2018
** server
** File description:
** get_tile_cont
*/

#include <stdio.h>
#include <string.h>
#include "board.h"
#include "dynbuf.h"
#include "game.h"
#include "msg.h"
#include "resource.h"

void board_gfx_get_tile_cont(board_t *bd, dynbuf_t *buf, vector2d_t pos)
{
	char strbuf[128];
	unsigned int *quantities;

	board_trunc_coords(bd, &pos);
	quantities = board_get(bd, pos);
	snprintf(strbuf, 128, ASW_TILE_CONT_FMT, pos.v_x, pos.v_y,
		quantities[0], quantities[1], quantities[2], quantities[3],
		quantities[4], quantities[5], quantities[6]);
	dynbuf_append_str(buf, strbuf);
}
