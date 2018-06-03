/*
** EPITECH PROJECT, 2018
** PSU_zappy_2017
** File description:
** player
*/

#ifndef PLAYER_H_
	#define PLAYER_H_

	#include "list.h"
	#include "board.h"
	#include "vector2d.h"

typedef struct		s_player {
	int		p_id;
	char		*p_teamname;
	char		*p_hostname;
	list_t		*p_queued_msgs;
	vector2d_t	p_pos;
	vector2d_t	p_dir;
}			player_t;

player_t *player_create(void);
player_t *player_create_at(vector2d_t pos);
void player_delete(void *ptr);
void player_move_foward(player_t *pl, board_t *bd);

#endif /* !PLAYER_H_ */
