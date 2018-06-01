/*
** EPITECH PROJECT, 2018
** PSU_zappy_2017
** File description:
** register_player
*/

#include "game.h"
#include "player.h"

void game_register_player(game_t *gm, player_t *pl)
{
	list_push_back(gm->ga_players, pl);
}
