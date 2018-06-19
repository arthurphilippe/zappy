/*
** EPITECH PROJECT, 2018
** server
** File description:
** consume_eggs
*/

#include <string.h>
#include "egg.h"
#include "team.h"
#include "gfx_hint.h"

static void consume_for_current_team(team_t *tm, list_t *eggs)
{
	egg_t *egg;
	list_iter_t iter;

	list_iter_init(&iter, eggs, FWD);
	while ((egg = list_iter_access(&iter)) && egg_has_hatched(egg)) {
		if (!strcmp(tm->t_name, egg->eg_team_name)) {
			tm->t_max_memb += 1;
			gfx_hint_eht(egg);
			list_erase(&iter);
		} else {
			list_iter_next(&iter);
		}
	}
}

void team_consume_eggs(list_t *teams, list_t *eggs)
{
	list_iter_t iter;
	team_t *tm;

	list_iter_init(&iter, teams, FWD);
	while ((tm = list_iter_next(&iter))) {
		consume_for_current_team(tm, eggs);
	}
}
