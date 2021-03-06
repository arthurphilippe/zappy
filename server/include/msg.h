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

	#define ASW_MAP_SIZE "msz %ld %ld\n"
	#define ASW_TILE_CONT "bct %s\n"
	#define ASW_TILE_CONT_FMT "%d %d %d %d %d %d %d %d %d"
	#define ASW_BAD_PARAM "sbp\n"
	#define ASW_TEAM_NAMES "sbp\n"
	#define ASW_PL_POS "ppo %d %d %d %d\n"
	#define ASW_PL_LVL "plv %d %d\n"
	#define ASW_PL_INV "pin %d %d %d %s\n"
	#define ASW_GET_FREQ "sgt %d\n"
	#define ASW_SET_FREQ "sst %d\n"

	#define HINT_NEW_PLAYER "pnw %d %d %d %d %d %s\n"
	#define HINT_KICK "pex %d\n"
	#define HINT_BROADCAST "pbc %d%s\n"
	#define HINT_START_INCANT "pic %d %d\n"
	#define HINT_END_INCANT "pie %d %d\n"
	#define HINT_EGG_LAID "enw %d %d %d %d\n"
	#define HINT_EGG_HACTHED "eht %d\n"
	#define HINT_EGG_USED "ebo %d\n"
	#define HINT_DROPED_RES "pdr %d %d\n"
	#define HINT_TOOK_RES "pgt %d %d\n"
	#define HINT_PLAYER_DIED "pdi %d\n"

	#define GFX_MAGIC "ZPPGFX88"

typedef struct		s_msg_map {
	const char	*mm_name;
	void		(*mm_func)
			(selector_t *stor, handle_t *hdl, list_t *args);
	unsigned int	mm_time_weight;
}			msg_map_t;

void msg_process(selector_t *stor, handle_t *hdl, const char *msg);
bool msg_process_cmd_pl(selector_t *stor, handle_t *hdl, list_t *msg);
void msg_process_cmd_gfx(selector_t *stor, handle_t *hdl, list_t *msg);

void msg_join(selector_t *stor, handle_t *hdl, player_t *pl,
		const char *msg);

#endif /* !MSG_H_ */
