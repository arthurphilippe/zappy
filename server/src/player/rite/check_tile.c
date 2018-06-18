/*
** EPITECH PROJECT, 2018
** server
** File description:
** check_tile
*/

#include "game.h"
#include "player.h"
#include "player_rite.h"

const rite_map_t RITE_MAP[] = {
	{{1, 0, 0, 0, 0, 0}, 1, 1},
	{{1, 1, 1, 0, 0, 0}, 2, 2},
	{{2, 0, 1, 0, 2, 0}, 3, 2},
	{{1, 1, 2, 0, 1, 0}, 4, 4},
	{{1, 2, 1, 3, 0, 0}, 5, 4},
	{{1, 2, 3, 0, 1, 0}, 6, 6},
	{{2, 2, 2, 2, 2, 1}, 7, 6},
	{{0}, 0, 0},
};

static const rite_map_t *find_key(player_t *pl)
{
	for (unsigned int i = 0; RITE_MAP[i].rim_level != 0; i++) {
		if (RITE_MAP[i].rim_level == pl->p_lvl)
			return (&RITE_MAP[i]);
	}
	return (NULL);
}

static bool check_for_pl_count(
	const rite_map_t *key, game_t *gm, player_t *pl)
{
	unsigned int count = game_count_players_lvl(gm, pl);

	return (count == key->rim_pl_nb);
}

static bool check_for_resources(
	const rite_map_t *key, board_t *bd, vector2d_t pos)
{
	unsigned int *quantities = board_get(bd, pos);

	for (unsigned int i = 1; i < RES_COUNT; i++) {
		if (quantities[i] != key->rim_resources[i - 1])
			return (false);
	}
	return (true);
}

bool player_rite_check_tile(player_t *pl, game_t *gm)
{
	const rite_map_t *key = find_key(pl);

	return (key && check_for_pl_count(key, gm, pl) &&
		check_for_resources(key, gm->ga_board, pl->p_pos));
}
