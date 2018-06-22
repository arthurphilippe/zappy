/*
** EPITECH PROJECT, 2018
** server
** File description:
** pie
*/

#include <stdio.h>
#include "gfx_hint.h"
#include "heading.h"
#include "msg.h"
#include "player.h"

void gfx_hint_pie(player_t *pl)
{
	if (gfx_hint_get_fd() != -1)
		dprintf(gfx_hint_get_fd(), HINT_END_INCANT,
			pl->p_pos.v_x, pl->p_pos.v_y);
}
