/*
** EPITECH PROJECT, 2018
** PSU_zappy_2017
** File description:
** look_at
*/

#include "board.h"
#include "game.h"
#include "dynbuf.h"
#include "resource.h"

static void search_for_player(game_t *gm, vector2d_t pos, dynbuf_t *buf)
{
	list_iter_t iter;
	player_t *pl;

	list_iter_init(&iter, gm->ga_players, FWD);
	while ((pl = list_iter_next(&iter))) {
		if (pl->p_pos.v_x == pos.v_x && pl->p_pos.v_y == pos.v_y)
			dynbuf_append_str(buf, " player");
	}
}

void board_look_at(board_t *bd, game_t *gm, vector2d_t pos, dynbuf_t *buf)
{
	char tile_content;

	board_trunc_coords(bd, &pos);
	tile_content = board_get(bd, pos);
	dynbuf_append_str(buf, resource_get_name(tile_content));
	search_for_player(gm, pos, buf);
}
