/*
** EPITECH PROJECT, 2018
** PSU_zappy_2017
** File description:
** eject
*/

#include <stdio.h>
#include "msg.h"
#include "game.h"
#include "player.h"
#include "gfx_hint.h"

void msg_cmd_pl_eject(selector_t *stor, handle_t *hdl, list_t *args)
{
	game_t *gm = stor->s_data;
	player_t *pl = hdl->h_data;

	(void) args;
	player_eject(pl, gm->ga_players, gm->ga_board);
	dprintf(hdl->h_fd, "ok\n");
	gfx_hint_pex(pl);
}
