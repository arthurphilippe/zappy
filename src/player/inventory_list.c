/*
** EPITECH PROJECT, 2018
** PSU_zappy_2017
** File description:
** inventory_list
*/

#include <stdlib.h>
#include <string.h>
#include "dynbuf.h"
#include "game.h"
#include "player.h"
#include "selector.h"

dynbuf_t *player_inventory_list(player_t *pl)
{
	dynbuf_t *buf = dynbuf_create();
	resource_t res = FOOD;
	const char *res_str;
	bool first = true;

	if (!buf)
		return (NULL);
	dynbuf_append_str(buf, "[");
	for (res_str = resource_get_name(res); strcmp(res_str, "");
		res_str = resource_get_name(res++)) {
		if (!first)
			dynbuf_append_str(buf, ", ");
		else
			first = false;
		dynbuf_append_str(buf, res_str);
		dynbuf_append_str(buf, " ");
		dynbuf_append_uint(buf, player_inventory_get(pl, res));
	}
	return (buf);
}
