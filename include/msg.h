/*
** EPITECH PROJECT, 2018
** PSU_zappy_2017
** File description:
** msg
*/

#ifndef MSG_H_
	#define MSG_H_

	#include "selector.h"
	#include "list.h"
	#include "player.h"

	#define CMD_GET_MAP_SIZE "msz"
	#define CMD_GET_TILE_CONTENT "bct"
	#define CMD_GET_MAP_CONTENT "mct"
	#define CMD_GET_TEAM_NAMES "tna"
	#define CMD_GET_PLAYER_POS "ppo"
	#define CMD_GET_PLAYER_LEVEL "plv"
	#define CMD_GET_PLAYER_INV "pin"
	#define CMD_GET_FREQ "sgt"
	#define CMD_SET_FREQ "sst"

	#define HINT_NEW_PLAYER "pnw #%ld %d %d %d %d %s\n"
	#define HINT_KICK "pex %ld\n"
	#define HINT_BROADCAST "pbc %ld %s\n"
	#define HINT_START_INCENT "pic %d %d %d"

typedef struct		s_msg_map {
	const char	*mm_name;
	void		(*mm_func)
			(selector_t *stor, handle_t *hdl, list_t *args);
	unsigned int	mm_time_weight;
}			msg_map_t;

void msg_process(selector_t *stor, handle_t *hdl, const char *msg);
void msg_join(selector_t *stor, handle_t *hdl, player_t *pl,
		const char *msg);
void msg_cmd_forward(selector_t *stor, handle_t *hdl, list_t *args);

#endif /* !MSG_H_ */
