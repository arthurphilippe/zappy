/*
** EPITECH PROJECT, 2018
** server
** File description:
** pnw
*/

#include <stdio.h>
#include "gfx_hint.h"
#include "heading.h"
#include "msg.h"
#include "player.h"

void gfx_hint_pnw(player_t *pl)
{
	if (gfx_hint_get_fd() != -1)
		dprintf(gfx_hint_get_fd(), HINT_NEW_PLAYER, pl->p_id,
			pl->p_pos.v_x, pl->p_pos.v_y,
			heading_get_code(pl->p_dir), pl->p_lvl,
			pl->p_teamname);
}
