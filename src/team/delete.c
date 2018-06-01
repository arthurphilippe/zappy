/*
** EPITECH PROJECT, 2018
** PSU_zappy_2017
** File description:
** delete
*/

#include <stdlib.h>
#include "team.h"

void team_delete(void *ptr)
{
	team_t *tm = ptr;

	free(tm->t_name);
	list_destroy(tm->t_membs);
	free(tm);
}
