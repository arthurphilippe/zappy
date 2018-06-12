/*
** EPITECH PROJECT, 2018
** PSU_zappy_2017
** File description:
** eject
*/

#include <stdlib.h>
#include "player.h"

void player_eject(player_t *pl, list_t *players, board_t *bd)
{
	player_t *tmp;
	list_iter_t *it = list_iter_create(players, FWD);

	for (tmp = list_iter_next(it); tmp != NULL;
		tmp = list_iter_next(it)) {
		if (tmp != pl && tmp->p_pos.v_x == pl->p_pos.v_x &&
			tmp->p_pos.v_y == pl->p_pos.v_y) {
			player_move_foward(tmp, bd);
		}
	}
	free(it);
}
