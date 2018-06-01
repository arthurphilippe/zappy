/*
** EPITECH PROJECT, 2018
** PSU_zappy_2017
** File description:
** team
*/

#ifndef TEAM_H_
	#define TEAM_H_

	#include "list.h"

typedef struct		s_team {
	char		*t_name;
	list_t		*t_membs;
	unsigned int	t_max_memb;
}			team_t;

team_t *team_create(const char *name, unsigned int max_memb);
void team_delete(void *ptr);

#endif /* !TEAM_H_ */
