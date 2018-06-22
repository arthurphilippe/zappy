/*
** EPITECH PROJECT, 2018
** server
** File description:
** pic
*/

#include <stdio.h>
#include "gfx_hint.h"
#include "heading.h"
#include "msg.h"
#include "player.h"

void gfx_hint_pic(player_t *pl)
{
	if (gfx_hint_get_fd() != -1)
		dprintf(gfx_hint_get_fd(), HINT_START_INCANT, pl->p_pos.v_x,
			pl->p_pos.v_y);
}
