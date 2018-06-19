/*
** EPITECH PROJECT, 2018
** server
** File description:
** ebo
*/

#include <stdio.h>
#include "egg.h"
#include "gfx_hint.h"
#include "msg.h"
#include "player.h"

void gfx_hint_ebo(egg_t *egg)
{
	if (gfx_hint_get_fd() != -1)
		dprintf(gfx_hint_get_fd(), HINT_EGG_USED, egg->eg_id);
}
