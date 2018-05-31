/*
** EPITECH PROJECT, 2018
** PSU_zappy_2017
** File description:
** game
*/

#ifndef GAME_H_
	#define GAME_H_

	#include "list.h"
	#include "board.h"

typedef struct		s_game {
	board_t		*ga_board;
	list_t		*ga_players;
	list_t		*ga_teams;
	unsigned int	ga_max_players;
	unsigned int	ga_freq;
}			game_t;

#endif /* !GAME_H_ */
