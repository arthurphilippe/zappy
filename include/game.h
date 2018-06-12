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
	#include "player.h"

typedef struct		s_game {
	board_t		*ga_board;
	list_t		*ga_players;
	list_t		*ga_teams;
	list_t		*ga_eggs;
	unsigned int	ga_max_players;
	unsigned int	ga_freq;
}			game_t;

game_t *game_create(unsigned int board_x, unsigned int board_y,
			unsigned int freq, unsigned int max_players);
void game_delete(void *ptr);
int game_register_player(game_t *gm, player_t *pl);
int game_add_team(game_t *gm, const char *name);
void game_unreg_player(game_t *gm, player_t *pl);
bool game_take_object(game_t *gm, player_t *pl, resource_t resource);
bool game_set_object(game_t *gm, player_t *pl, resource_t resource);

#endif /* !GAME_H_ */
