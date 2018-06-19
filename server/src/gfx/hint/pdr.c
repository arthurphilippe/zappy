/*
** EPITECH PROJECT, 2018
** server
** File description:
** pdr
*/

#include <stdio.h>
#include "gfx_hint.h"
#include "msg.h"
#include "player.h"

void gfx_hint_pdr(player_t *pl, unsigned int res)
{
	if (gfx_hint_get_fd() != -1)
		dprintf(gfx_hint_get_fd(), HINT_DROPED_RES, pl->p_id, res);
}
