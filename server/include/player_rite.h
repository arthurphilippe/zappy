/*
** EPITECH PROJECT, 2018
** server
** File description:
** player_rite
*/

#ifndef PLAYER_RITE_H_
	#define PLAYER_RITE_H_

	#include "resource.h"

typedef struct		s_rite_map {
	unsigned int	rim_resources[RES_COUNT];
	unsigned int	rim_level;
	unsigned int	rim_pl_nb;
}			rite_map_t;

bool player_rite_check_tile(player_t *pl, game_t *gm);

#endif /* !PLAYER_RITE_H_ */
