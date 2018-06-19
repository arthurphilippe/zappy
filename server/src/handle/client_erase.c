/*
** EPITECH PROJECT, 2018
** PSU_zappy_2017
** File description:
** client_erase
*/

#include <stdio.h>
#include <unistd.h>
#include "selector.h"
#include "game.h"
#include "gfx_hint.h"

/*
** What to do when we want to get rid of a client handle.
*/
void client_erase(selector_t *stor, handle_t *hdl)
{
	if (hdl->h_type == H_PLAYER) {
		game_unreg_player(stor->s_data, hdl->h_data);
	} else if (hdl->h_type == H_GFX) {
		gfx_hint_init(-1);
	}
	list_find_and_delete_addr(stor->s_handles, hdl);
}
