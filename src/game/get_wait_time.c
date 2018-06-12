/*
** EPITECH PROJECT, 2018
** PSU_zappy_2017
** File description:
** get_wait_time
*/

#include "game.h"
#include "get_wait_time.h"

unsigned int game_get_wait_time(game_t *gm, unsigned int weight)
{
	return (get_wait_time(gm->ga_freq, weight));
}
