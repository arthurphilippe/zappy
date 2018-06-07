/*
** EPITECH PROJECT, 2018
** PSU_zappy_2017
** File description:
** client_erase
*/

#include <stdio.h>
#include <unistd.h>
#include "selector.h"
#include "game.h"

void client_erase(selector_t *stor, handle_t *hdl)
{
	game_unreg_player(stor->s_data, hdl->h_data);
	list_find_and_delete_addr(stor->s_handles, hdl);
}
