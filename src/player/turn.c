/*
** EPITECH PROJECT, 2018
** PSU_zappy_2017
** File description:
** turn
*/

#include "player.h"

void player_turn_right(player_t *pl)
{
	if (pl->p_dir.v_x == 1) {
		pl->p_dir.v_y = -1;
		pl->p_dir.v_x = 0;
		return;
	}
	if (pl->p_dir.v_x == -1) {
		pl->p_dir.v_y = 1;
		pl->p_dir.v_x = 0;
		return;
	}
	if (pl->p_dir.v_y == 1) {
		pl->p_dir.v_x = 1;
		pl->p_dir.v_y = 0;
		return;
	}
	if (pl->p_dir.v_y == -1) {
		pl->p_dir.v_x = -1;
		pl->p_dir.v_y = 0;
		return;
	}
}

void player_turn_left(player_t *pl)
{
	if (pl->p_dir.v_x == 1) {
		pl->p_dir.v_y = 1;
		pl->p_dir.v_x = 0;
		return;
	}
	if (pl->p_dir.v_x == -1) {
		pl->p_dir.v_y = -1;
		pl->p_dir.v_x = 0;
		return;
	}
	if (pl->p_dir.v_y == 1) {
		pl->p_dir.v_x = -1;
		pl->p_dir.v_y = 0;
		return;
	}
	if (pl->p_dir.v_y) {
		pl->p_dir.v_x = 1;
		pl->p_dir.v_y = 0;
		return;
	}
}
