/*
** EPITECH PROJECT, 2018
** server
** File description:
** enw
*/

#include <stdio.h>
#include "egg.h"
#include "gfx_hint.h"
#include "msg.h"
#include "player.h"

void gfx_hint_enw(player_t *pl, egg_t *egg)
{
	if (gfx_hint_get_fd() != -1)
		dprintf(gfx_hint_get_fd(), HINT_EGG_LAID, egg->eg_id,
			pl->p_id, pl->p_pos.v_x, pl->p_pos.v_y);
}
