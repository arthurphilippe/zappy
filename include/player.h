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
	char		*p_teamname;
	char		*p_hostname;
	list_t		*p_queued_msgs;
	vector2d_t	p_pos;
	vector2d_t	p_dir;
	int		p_id;
	unsigned int	p_lvl;
}			player_t;

typedef struct		s_look_key {
	vector2d_t	lk_pl_dir;
	vector2d_t	lk_start_mod;
	vector2d_t	lk_line_dir;
}			look_key_t;

player_t *player_create(void);
player_t *player_create_at(vector2d_t pos);
void player_delete(void *ptr);
void player_move_foward(player_t *pl, board_t *bd);
void player_turn_right(player_t *pl);
void player_turn_left(player_t *pl);

#endif /* !PLAYER_H_ */
