/*
** EPITECH PROJECT, 2018
** PSU_zappy_2017
** File description:
** egg
*/

#ifndef EGG_H_
	#define EGG_H_

	#include <stdbool.h>
	#include "vector2d.h"

typedef struct chrono_s chrono_t;

typedef struct		s_egg {
	char		*eg_team_name;
	chrono_t	*eg_timer;
	vector2d_t	eg_pos;
}			egg_t;

egg_t *egg_create(const char *team, vector2d_t pos, unsigned int freq);
void egg_delete(void *ptr);
bool egg_has_hatched(egg_t *egg);

#endif /* !EGG_H_ */
