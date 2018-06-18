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
	#include "delayed_cmd.h"
	#include "chrono.h"

	#define LIFE_EXPECTANCY 126

typedef struct		s_player {
	unsigned int	p_inventory[10];
	delayed_cmd_t	p_task;
	chrono_t	p_lifespan;
	char		*p_teamname;
	list_t		*p_queued_msgs;
	vector2d_t	p_pos;
	vector2d_t	p_dir;
	unsigned int	p_lvl;
}			player_t;

typedef struct		s_look_key {
	vector2d_t	lk_pl_dir;
	vector2d_t	lk_start_mod;
	vector2d_t	lk_line_dir;
}			look_key_t;

/*
** Forward declarations of dynbuf & game.
*/
typedef struct	s_dynbuf dynbuf_t;
typedef struct	s_game game_t;
typedef struct	s_selector selector_t;
typedef struct	s_handle handle_t;

void player_on_cycle(selector_t *stor, handle_t *hdl);

player_t *player_create(void);
player_t *player_create_at(vector2d_t pos);
void player_delete(void *ptr);
void player_move_foward(player_t *pl, board_t *bd);
void player_turn_right(player_t *pl);
void player_turn_left(player_t *pl);
dynbuf_t *player_look(player_t *pl, game_t *gm);

void player_inventory_add(player_t *pl, resource_t resource);
void player_inventory_rem(player_t *pl, resource_t resource);
unsigned int player_inventory_get(player_t *pl, resource_t resource);
dynbuf_t *player_inventory_list(player_t *pl);
dynbuf_t *player_inventory_list_gfx(player_t *pl);
void player_eject(player_t *pl, list_t *players, board_t *bd);
void player_lifespan_check(player_t *pl);

#endif /* !PLAYER_H_ */
