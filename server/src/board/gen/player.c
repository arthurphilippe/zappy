/*
** EPITECH PROJECT, 2018
** Zappy
** File description:
** Created by hexa,
*/

#include "player.h"
#include "team.h"

unsigned int count_players(list_t *teams)
{
	team_t *tm;
	list_iter_t iter;
	unsigned int count = 0;

	list_iter_init(&iter, teams, FWD);
	while ((tm = list_iter_next(&iter)))
		count += tm->t_membs->l_size;
	return (count);
}
