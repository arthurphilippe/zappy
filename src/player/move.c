/*
** EPITECH PROJECT, 2018
** PSU_zappy_2017
** File description:
** move
*/

#include "player.h"

void player_move_foward(player_t *pl, board_t *bd)
{
	pl->p_pos.v_x += pl->p_dir.v_x;
	pl->p_pos.v_y += pl->p_dir.v_y;
	pl->p_pos.v_x %= bd->b_max_x;
	pl->p_pos.v_y %= bd->b_max_y;
	if (pl->p_pos.v_x < 0)
		pl->p_dir.v_x = bd->b_max_x - pl->p_dir.v_x;
	if (pl->p_pos.v_y < 0)
		pl->p_dir.v_y = bd->b_max_x - pl->p_dir.v_y;
}
