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

void board_look_at(board_t *bd, game_t *gm, vector2d_t pos, dynbuf_t *buf)
{
	resource_t resource;
	unsigned int food_qtt;
	bool first = true;

	board_trunc_coords(bd, &pos);
	resource = board_get_resource(bd, pos);
	food_qtt = board_get_food(bd, pos);
	for (unsigned int i = 0; i < food_qtt; i++) {
		append_str(buf, "food", &first);
	}
	append_str(buf, resource_get_name(resource), &first);
	search_for_players(gm, pos, buf, first);
}
