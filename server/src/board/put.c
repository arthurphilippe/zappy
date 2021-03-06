/*
** EPITECH PROJECT, 2018
** PSU_zappy_2017
** File description:
** put
*/

#include "board.h"
#include "vector2d.h"
#include "resource.h"

/*
** sets the tile resource to the param.
*/
void board_put_resource(board_t *bd, vector2d_t pos, resource_t resource)
{
	size_t idx;

	board_trunc_coords(bd, &pos);
	idx = board_get_idx(bd, pos.v_x, pos.v_y);
	bd->b_data[idx][resource] += 1;
}

bool board_take_resource(board_t *bd, vector2d_t pos, resource_t resource)
{
	size_t idx;
	bool ret = true;

	board_trunc_coords(bd, &pos);
	idx = board_get_idx(bd, pos.v_x, pos.v_y);
	if (bd->b_data[idx][resource])
		bd->b_data[idx][resource] -= 1;
	else
		ret = false;
	return (ret);
}

/*
** increments the food count on tile by 1 if it is inferior to 8.
*/
void board_inc_food(board_t *bd, vector2d_t pos)
{
	size_t idx;

	board_trunc_coords(bd, &pos);
	idx = board_get_idx(bd, pos.v_x, pos.v_y);
	bd->b_data[idx][FOOD] += 1;
}

/*
** decrements the food count on tile by 1 if it is superior to 1.
*/
bool board_dec_food(board_t *bd, vector2d_t pos)
{
	size_t idx;
	bool ret = true;

	board_trunc_coords(bd, &pos);
	idx = board_get_idx(bd, pos.v_x, pos.v_y);
	if (bd->b_data[idx][FOOD])
		bd->b_data[idx][FOOD] -= 1;
	else
		ret = false;
	return (ret);
}
