/*
** EPITECH PROJECT, 2018
** PSU_zappy_2017
** File description:
** set
*/

#include <stdio.h>
#include "game.h"
#include "gfx_hint.h"
#include "msg.h"
#include "player.h"

void msg_cmd_pl_set(selector_t *stor, handle_t *hdl, list_t *args)
{
	bool ret = false;
	resource_t val;

	if (args->l_size >= 1) {
		val = resource_get_value(args->l_start->n_data);
		ret = game_take_object(stor->s_data, hdl->h_data, val);
	}
	dprintf(hdl->h_fd, (!ret) ? "ko\n" : "ok\n");
	if (ret)
		gfx_hint_pdr(hdl->h_data, val);
}
