/*
** EPITECH PROJECT, 2018
** server
** File description:
** consume_eggs
*/

#include <stdlib.h>
#include <string.h>
#include "egg.h"
#include "team.h"
#include "gfx_hint.h"

static void move_hatched_egg_to_team(team_t *tm, egg_t *egg)
{
	egg_t *cpy = malloc(sizeof(egg_t));

	if (cpy) {
		cpy->eg_id = egg->eg_id;
		cpy->eg_pos.v_x = egg->eg_pos.v_x;
		cpy->eg_pos.v_y = egg->eg_pos.v_y;
		cpy->eg_team_name = NULL;
		cpy->eg_timer = NULL;
		list_push_back(tm->t_hatched_eggs, cpy);
	}
}

static void consume_for_current_team(team_t *tm, list_t *eggs)
{
	egg_t *egg;
	list_iter_t iter;

	list_iter_init(&iter, eggs, FWD);
	while ((egg = list_iter_access(&iter)) && egg_has_hatched(egg)) {
		if (!strcmp(tm->t_name, egg->eg_team_name)) {
			gfx_hint_eht(egg);
			move_hatched_egg_to_team(tm, egg);
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
