/*
** EPITECH PROJECT, 2018
** PSU_zappy_2017
** File description:
** look_at
*/

#include "board.h"
#include "dynbuf.h"
#include "game.h"
#include "resource.h"

static void append_str(dynbuf_t *buf, const char *str, bool *first)
{
	if (!(*first)) {
		dynbuf_append_str(buf, " ");
	} else
		*first = false;
	dynbuf_append_str(buf, str);
}

static void search_for_players(
	game_t *gm, vector2d_t pos, dynbuf_t *buf, bool first)
{
	list_iter_t iter;
	player_t *pl;

	list_iter_init(&iter, gm->ga_players, FWD);
	while ((pl = list_iter_next(&iter))) {
		if (pl->p_pos.v_x == pos.v_x && pl->p_pos.v_y == pos.v_y)
			append_str(buf, "player", &first);
	}
}

static void append_res(dynbuf_t *buf, unsigned count, const char *name, bool *first)
{
	for (unsigned int i = 0; i < count; i++) {
		append_str(buf, name, first);
	}
}

void board_look_at(board_t *bd, game_t *gm, vector2d_t pos, dynbuf_t *buf)
{
	unsigned int *tile;
	bool first = true;

	board_trunc_coords(bd, &pos);
	tile = board_get(bd, pos);
	for (unsigned int i = 0; i < RES_COUNT; i++) {
		append_res(buf, tile[i], resource_get_name(i), &first);
	}
	search_for_players(gm, pos, buf, first);
}
