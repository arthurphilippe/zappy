/*
** EPITECH PROJECT, 2018
** PSU_zappy_2017
** File description:
** fork
*/

#include <stdio.h>
#include "msg.h"
#include "egg.h"
#include "game.h"
#include "gfx_hint.h"

void msg_cmd_pl_fork(selector_t *stor, handle_t *hdl, list_t *args)
{
	game_t *gm = stor->s_data;
	player_t *pl = hdl->h_data;
	egg_t *egg = egg_create(pl->p_teamname, pl->p_pos, gm->ga_freq);

	(void) args;
	list_push_back(gm->ga_eggs, egg);
	dprintf(hdl->h_fd, "ok\n");
	gfx_hint_enw(pl, egg);
}

