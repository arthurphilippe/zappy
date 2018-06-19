/*
** EPITECH PROJECT, 2018
** Zappy
** File description:
** Created by hexa
*/

#ifndef BOARD_GEN_H_
	#define BOARD_GEN_H_

	#include "list.h"
	#include "team.h"
	#include "board.h"

/*
** PROCEDURAL RULES Struct
*/
typedef struct		s_procedural_rule {
	resource_t	type;
	int 		number;
}			procedural_rule_t;

/*
** RANDOMNESS
*/
int random_int(int, int);

/*
** RESOURCES GEN
*/
void board_gen(board_t *, list_t *);
unsigned int count_players(list_t *);
unsigned int get_max_level_reachable(list_t *);
unsigned int *get_levels_reachable(unsigned int [7], list_t *);

#endif /* !BOARD_GEN_H_ */
