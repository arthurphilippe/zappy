/*
** EPITECH PROJECT, 2018
** PSU_zappy_2017
** File description:
** process
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "chrono.h"
#include "game.h"
#include "get_wait_time.h"
#include "msg.h"
#include "msg_cmd_pl.h"
#include "player.h"
#include "selector.h"
#include "stolist.h"
#include "gfx_hint.h"

const msg_map_t MSG_CMD_PL_MAP[] = {
	{"Forward", msg_cmd_pl_forward, 7},
	{"Right", msg_cmd_pl_right, 7},
	{"Left", msg_cmd_pl_left, 7},
	{"Look", msg_cmd_pl_look, 7},
	{"Inventory", msg_cmd_pl_inventory, 1},
	{"Broadcast", msg_cmd_pl_boradcast, 7},
	{"Connect_nbr", msg_cmd_pl_connect_nbr, 0},
	{"Fork", msg_cmd_pl_fork, 42},
	{"Eject", msg_cmd_pl_eject, 7},
	{"Take", msg_cmd_pl_take, 7},
	{"Set", msg_cmd_pl_set, 7},
	{"Incantation", msg_cmd_pl_incentation, 0},
	{NULL, NULL, 0},
};

static bool set_pending_task(
	list_t *msg, player_t *pl, game_t *gm, const msg_map_t *key)
{
	list_pop_front(msg);
	pl->p_task.dc_args = msg;
	chrono_init(&pl->p_task.dc_timer,
		get_wait_time(gm->ga_freq, key->mm_time_weight));
	pl->p_task.dc_callback = key->mm_func;
	return (false);
}

static bool find_and_prepare_cmd(selector_t *stor, list_t *msg, player_t *pl)
{
	char *cmd_name;
	game_t *gm = stor->s_data;

	if (!msg || !msg->l_size)
		return (true);
	cmd_name = msg->l_start->n_data;
	for (unsigned int i = 0; MSG_CMD_PL_MAP[i].mm_name; i++) {
		if (!strcasecmp(cmd_name, MSG_CMD_PL_MAP[i].mm_name) &&
			MSG_CMD_PL_MAP[i].mm_func) {
			set_pending_task(msg, pl, gm, &MSG_CMD_PL_MAP[i]);
			return (false);
		}
	}
	return (true);
}

static void process_unregistred(
	selector_t *stor, handle_t *hdl, player_t *pl, const char *str)
{
	if (!strcmp(str, GFX_MAGIC)) {
		hdl->h_delete(hdl->h_data);
		hdl->h_data = list_create(free);
		hdl->h_delete = (void (*)(void *)) list_destroy;
		hdl->h_type = H_GFX;
		hdl->h_on_cycle = NULL;
		gfx_hint_init(hdl->h_fd);
	} else {
		msg_join(stor, hdl, pl, str);
	}
}

bool msg_process_cmd_pl(selector_t *stor, handle_t *hdl, list_t *msg)
{
	player_t *pl = hdl->h_data;
	bool ret;

	(void) hdl;
	if (!pl->p_teamname && msg->l_size) {
		process_unregistred(stor, hdl, pl, msg->l_start->n_data);
		ret = true;
	} else {
		ret = find_and_prepare_cmd(stor, msg, pl);
	}
	return (ret);
}
