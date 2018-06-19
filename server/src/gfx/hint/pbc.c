/*
** EPITECH PROJECT, 2018
** server
** File description:
** pbc
*/

#include <stdio.h>
#include "gfx_hint.h"
#include "msg.h"
#include "player.h"

void gfx_hint_pbc(player_t *pl, const char *str)
{
	if (gfx_hint_get_fd() != -1)
		dprintf(gfx_hint_get_fd(), HINT_BROADCAST, pl->p_id, str);
}
