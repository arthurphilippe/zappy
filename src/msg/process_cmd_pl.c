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

const msg_map_t msg_cmd_pl_MAP[] = {
	{"Forward", msg_cmd_pl_forward, 7},
	{"Right", msg_cmd_pl_right, 7},
	{"Left", msg_cmd_pl_left, 7},
	{"Look", msg_cmd_pl_look, 7},
	{"Inventory", NULL, 1},
	{"Broadcast", NULL, 7},
	{"Connect_nbr", NULL, 0},
	{"Fork", NULL, 42},
	{"Eject", NULL, 7},
	{"Take", NULL, 7},
	{"Set", NULL, 7},
	{"Incantation", NULL, 300},
	{CMD_GET_MAP_SIZE, NULL, 0},
	{CMD_GET_TILE_CONTENT, NULL, 0},
	{CMD_GET_MAP_CONTENT, NULL, 0},
	{CMD_GET_TEAM_NAMES, NULL, 0},
	{CMD_GET_PLAYER_POS, NULL, 0},
	{CMD_GET_PLAYER_LEVEL, NULL, 0},
	{CMD_GET_PLAYER_INV, NULL, 0},
	{CMD_GET_FREQ, NULL, 0},
	{CMD_SET_FREQ, NULL, 0},
	{NULL, NULL, 0},
};

static void find_and_run_cmd(selector_t *stor, handle_t *hdl, list_t *msg)
{
	char *cmd_name;

	if (!msg || !msg->l_size)
		return;
	cmd_name = msg->l_start->n_data;
	for (unsigned int i = 0; msg_cmd_pl_MAP[i].mm_name; i++) {
		if (!strcasecmp(cmd_name, msg_cmd_pl_MAP[i].mm_name) &&
			msg_cmd_pl_MAP[i].mm_func) {
			list_pop_front(msg);
			msg_cmd_pl_MAP[i].mm_func(stor, hdl, msg);
			return;
		}
	}
}

void msg_process_cmd_pl(selector_t *stor, handle_t *hdl, list_t *msg)
{
	player_t *pl = hdl->h_data;

	if (!pl->p_teamname && msg->l_size)
		msg_join(stor, hdl, pl, msg->l_start->n_data);
	else
		find_and_run_cmd(stor, hdl, msg);
}
