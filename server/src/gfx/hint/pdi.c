/*
** EPITECH PROJECT, 2018
** server
** File description:
** pdi
*/

#include <stdio.h>
#include "gfx_hint.h"
#include "msg.h"
#include "player.h"

void gfx_hint_pdi(player_t *pl)
{
	if (gfx_hint_get_fd() != -1 && pl->p_id)
		dprintf(gfx_hint_get_fd(), HINT_PLAYER_DIED, pl->p_id);
}
