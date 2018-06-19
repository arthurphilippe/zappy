/*
** EPITECH PROJECT, 2018
** PSU_zappy_2017
** File description:
** register_player
*/

#include "game.h"
#include "player.h"
#include "team.h"
#include "get_wait_time.h"
#include "egg.h"
#include "gfx_hint.h"

static bool use_egg(team_t *tm, player_t *pl)
{
	egg_t *egg;

	if (!tm->t_hatched_eggs->l_size)
		return (false);
	egg = tm->t_hatched_eggs->l_start->n_data;
	pl->p_pos.v_x = egg->eg_pos.v_x;
	pl->p_pos.v_y = egg->eg_pos.v_y;
	list_pop_front(tm->t_hatched_eggs);
	tm->t_max_memb += 1;
	gfx_hint_ebo(egg);
	return (true);
}

int game_register_player(game_t *gm, player_t *pl)
{
	static unsigned int id = 0;
	team_t *tm = team_find_by_name(gm->ga_teams, pl->p_teamname);

	if (!tm || (!tm->t_max_memb && !use_egg(tm, pl)))
		return (-1);
	if (list_push_back(gm->ga_players, pl) != LIST_OK ||
		list_push_back(tm->t_membs, pl) != LIST_OK)
		return (-1);
	chrono_init(&pl->p_lifespan, get_wait_time(gm->ga_freq, 126));
	pl->p_id = ++id;
	return (--tm->t_max_memb);
}
