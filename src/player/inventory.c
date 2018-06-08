/*
** EPITECH PROJECT, 2018
** PSU_zappy_2017
** File description:
** inventory
*/

#include "player.h"
#include "resource.h"

void player_inventory_add(player_t *pl, resource_t resource)
{
	pl->p_inventory[resource] += 1;
}

void player_inventory_rem(player_t *pl, resource_t resource)
{
	if (pl->p_inventory[resource])
		pl->p_inventory[resource] -= 1;
}

unsigned int player_inventory_get(player_t *pl, resource_t resource)
{
	return (pl->p_inventory[resource]);
}
