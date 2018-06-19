/*
** EPITECH PROJECT, 2018
** PSU_zappy_2017
** File description:
** take
*/

#include <stdio.h>
#include "game.h"
#include "gfx_hint.h"
#include "msg.h"
#include "player.h"

void msg_cmd_pl_take(selector_t *stor, handle_t *hdl, list_t *args)
{
	bool ret = false;
	resource_t val;

	if (args && args->l_size >= 1) {
		val = resource_get_value(args->l_end->n_data);
		if (val != (unsigned int) -1)
			ret = game_take_object(stor->s_data, hdl->h_data, val);
	}
	dprintf(hdl->h_fd, (!ret) ? "ko\n" : "ok\n");
	if (ret)
		gfx_hint_pgt(hdl->h_data, val);
}
