/*
** EPITECH PROJECT, 2018
** Zappy
** File description:
** Created by hexa,
*/

#include "board_gen.h"

const procedural_rule_t rules[][6] = {
	{{LINEMATE, 1}, {DERAUMERE, 0}, {SIBUR, 0}, {MENDIANE, 0},
		{PHIRAS, 0}, {THYSTAME, 0}},
	{{LINEMATE, 1}, {DERAUMERE, 1}, {SIBUR, 1}, {MENDIANE, 0},
		{PHIRAS, 0}, {THYSTAME, 0}},
	{{LINEMATE, 2}, {DERAUMERE, 0}, {SIBUR, 1}, {MENDIANE, 0},
		{PHIRAS, 2}, {THYSTAME, 0}},
	{{LINEMATE, 1}, {DERAUMERE, 1}, {SIBUR, 2}, {MENDIANE, 0},
		{PHIRAS, 1}, {THYSTAME, 0}},
	{{LINEMATE, 1}, {DERAUMERE, 2}, {SIBUR, 1}, {MENDIANE, 3},
		{PHIRAS, 0}, {THYSTAME, 0}},
	{{LINEMATE, 1}, {DERAUMERE, 2}, {SIBUR, 3}, {MENDIANE, 0},
		{PHIRAS, 1}, {THYSTAME, 0}},
	{{LINEMATE, 2}, {DERAUMERE, 2}, {SIBUR, 2}, {MENDIANE, 2},
		{PHIRAS, 2}, {THYSTAME, 1}}
};

static void board_gen_resource(board_t *board, resource_t type, int nb)
{
	vector2d_t pos;

	for (int i = 0; i < nb; i++) {
		pos.v_x = random_int(0, (int) board->b_max_x);
		pos.v_y = random_int(0, (int) board->b_max_y);
		board_put_resource(board, pos, type);
	}
}

void board_gen(board_t *board, list_t *teams)
{
	unsigned int levels[7];
	unsigned int nb_players;
	const procedural_rule_t *rule;

	get_levels_reachable(levels, teams);
	board_gen_resource(board, FOOD, count_players(teams) * 25);
	for (unsigned int level = 0; level < 7; level++) {
		rule = (levels[level] == 1) ? rules[level] : 0;
		nb_players = count_players_by_level(teams, level + 1);
		for (int i = 0; i < 6 && rule != 0; i++) {
			board_gen_resource(board, rule[i].type,
				nb_players * rule[i].number);
		}
	}
}
