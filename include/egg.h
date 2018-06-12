/*
** EPITECH PROJECT, 2018
** PSU_zappy_2017
** File description:
** egg
*/

#ifndef EGG_H_
	#define EGG_H_

	#include "vector2d.h"

typedef struct		s_egg {
	char		*eg_team_name;
	void		*eg_timer;
	vector2d_t	eg_pos;
}			egg_t;

egg_t *egg_create(const char *team);
void egg_delete(void *ptr);

#endif /* !EGG_H_ */
