/*
** EPITECH PROJECT, 2018
** server
** File description:
** heading
*/

#ifndef HEADING_H_
	#define HEADING_H_

	#include "vector2d.h"

typedef enum	e_heading {
	NORTH = 1,
	EAST,
	SOUTH,
	WEST
}		heading_t;

typedef struct		s_heading_key {
	heading_t	hk_heading;
	vector2d_t	hk_vec;
}			heading_key_t;

unsigned int heading_get_code(vector2d_t dir);

#endif /* !HEADING_H_ */
