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
team_t *team_find_by_name(list_t *teams, const char *name);
void team_consume_eggs(list_t *teams, list_t *eggs);

#endif /* !TEAM_H_ */
