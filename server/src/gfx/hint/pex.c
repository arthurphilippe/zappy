/*
** EPITECH PROJECT, 2018
** server
** File description:
** pex
*/

#include <stdio.h>
#include "gfx_hint.h"
#include "msg.h"
#include "player.h"

void gfx_hint_pex(player_t *pl)
{
	if (gfx_hint_get_fd() != -1)
		dprintf(gfx_hint_get_fd(), HINT_KICK, pl->p_id);
}
