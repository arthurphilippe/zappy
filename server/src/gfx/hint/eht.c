/*
** EPITECH PROJECT, 2018
** server
** File description:
** eht
*/

#include <stdio.h>
#include "egg.h"
#include "gfx_hint.h"
#include "msg.h"
#include "player.h"

void gfx_hint_eht(egg_t *egg)
{
	if (gfx_hint_get_fd() != -1)
		dprintf(gfx_hint_get_fd(), HINT_EGG_HACTHED, egg->eg_id);
}
