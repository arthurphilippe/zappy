/*
** EPITECH PROJECT, 2018
** PSU_zappy_2017
** File description:
** look
*/

#include <stdio.h>
#include "player.h"
#include "game.h"
#include "selector.h"
#include "dynbuf.h"

const look_key_t LOOK_MAP[] = {
	{{1, 0}, {1, -1}, {0, 1}},
	{{-1, 0}, {-1, 1}, {0, -1}},
	{{0, 1}, {1, 1}, {-1, 0}},
	{{0, -1}, {-1, -1}, {1, 0}},
};

static const look_key_t *get_look_key(vector2d_t dir)
{
	for (unsigned int i = 0; i < 4; i++) {
		if (LOOK_MAP[i].lk_pl_dir.v_x == dir.v_x
			&& LOOK_MAP[i].lk_pl_dir.v_y == dir.v_y) {
			return (&LOOK_MAP[i]);
		}
	}
	return (LOOK_MAP);
}

static void update_line_start(vector2d_t *pt, const look_key_t *key)
{
	pt->v_x += key->lk_line_dir.v_x;
	pt->v_y += key->lk_line_dir.v_y;
}

static void display_line(vector2d_t pt, const look_key_t *key,
				game_t *gm, int depth)
{
	unsigned int width = (depth * 2) + 1;

	for (unsigned int i = 0; i < width; i++) {

	}
}

void player_look(player_t *pl, int fd, game_t *gm)
{
	dynbuf_t *buf = dynbuf_create();
	vector2d_t line_start = pl->p_pos;
	const look_key_t *key = get_look_key(pl->p_dir);

	dynbuf_append_str(buf, "[");
	for (unsigned int i = 0; i < pl->p_lvl; i++) {
		update_line_start(&line_start, key);
		display_line(line_start, key, gm, i + 1);
	}
}
