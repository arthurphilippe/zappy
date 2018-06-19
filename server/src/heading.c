/*
** EPITECH PROJECT, 2018
** server
** File description:
** heading
*/

#include "heading.h"

const heading_key_t HEADING_MAP[] = {
	{NORTH, {0, -1}},
	{SOUTH, {0, 1}},
	{EAST, {1, 0}},
	{WEST, {-1, 0}},
};

unsigned int heading_get_code(vector2d_t dir)
{
	for (unsigned int i = 0; i < 4; i++) {
		if (dir.v_x == HEADING_MAP[i].hk_vec.v_x &&
			dir.v_y == HEADING_MAP[i].hk_vec.v_y) {
			return (HEADING_MAP[i].hk_heading);
		}
	}
	return (0);
}
