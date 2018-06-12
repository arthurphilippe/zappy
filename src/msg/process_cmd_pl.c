/*
** EPITECH PROJECT, 2018
** PSU_zappy_2017
** File description:
** process
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "msg.h"
#include "msg_cmd_pl.h"
#include "player.h"
#include "selector.h"
#include "stolist.h"

const msg_map_t MSG_CMD_PL_MAP[] = {
	{"Forward", msg_cmd_pl_forward, 7},
	{"Right", msg_cmd_pl_right, 7},
	{"Left", msg_cmd_pl_left, 7},
	{"Look", msg_cmd_pl_look, 7},
	{"Inventory", msg_cmd_pl_inventory, 1},
	{"Broadcast", msg_cmd_pl_boradcast, 7},
	{"Connect_nbr", msg_cmd_pl_connect_nbr, 0},
	{"Fork", NULL, 42},
	// {"Eject", msg_cmd_pl_eject, 7},
	{"Take", msg_cmd_pl_take, 7},
	{"Set", msg_cmd_pl_set, 7},
	{"Incantation", NULL, 300},
	{NULL, NULL, 0},
};

static void find_and_run_cmd(selector_t *stor, handle_t *hdl, list_t *msg)
{
	char *cmd_name;

	if (!msg || !msg->l_size)
		return;
	cmd_name = msg->l_start->n_data;
	for (unsigned int i = 0; MSG_CMD_PL_MAP[i].mm_name; i++) {
		if (!strcasecmp(cmd_name, MSG_CMD_PL_MAP[i].mm_name) &&
			MSG_CMD_PL_MAP[i].mm_func) {
			list_pop_front(msg);
			MSG_CMD_PL_MAP[i].mm_func(stor, hdl, msg);
			return;
		}
	}
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
	} else {
		msg_join(stor, hdl, pl, str);
	}
}

void msg_process_cmd_pl(selector_t *stor, handle_t *hdl, list_t *msg)
{
	player_t *pl = hdl->h_data;

	if (!pl->p_teamname && msg->l_size)
		process_unregistred(stor, hdl, pl, msg->l_start->n_data);
	else
		find_and_run_cmd(stor, hdl, msg);
}
