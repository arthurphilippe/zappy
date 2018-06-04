/*
** EPITECH PROJECT, 2018
** PSU_zappy_2017
** File description:
** process
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "selector.h"
#include "stolist.h"
#include "msg.h"
#include "player.h"

const msg_map_t MSG_CMD_MAP[] = {
	{"Forward", msg_cmd_forward, 7},
	{"Right", NULL, 7},
	{"Left", NULL, 7},
	{"Look", NULL, 7},
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

static void debug_list(list_t *list)
{
	list_iter_t *iter = list_iter_create(list, FWD);
	char *tmp;

	dprintf(2, "----------\ndebug list contents: %ld\n", list->l_size);
	if (!iter)
		return;
	while ((tmp = list_iter_next(iter)))
		dprintf(2, "%s\n", tmp);
	free(iter);
}

static void find_and_run_cmd(selector_t *stor, handle_t *hdl, list_t *msg)
{
	char *cmd_name;

	if (!msg || !msg->l_size)
		return;
	cmd_name = msg->l_start->n_data;
	for (unsigned int i = 0; MSG_CMD_MAP[i].mm_name; i++) {
		if (!strcasecmp(cmd_name, MSG_CMD_MAP[i].mm_name)
			&& MSG_CMD_MAP[i].mm_func) {
			list_pop_front(msg);
			MSG_CMD_MAP[i].mm_func(stor, hdl, msg);
		}
	}
}

void msg_process(selector_t *stor, handle_t *hdl, const char *msg)
{
	list_t *split_msg = stolist(msg, " ");
	player_t *pl = hdl->h_data;

	(void) stor;
	dprintf(2, "debug: processing %s\n", msg);
	if (!split_msg)
		return;
	debug_list(split_msg);
	if (!pl->p_teamname && split_msg->l_size)
		msg_join(stor, hdl, pl, split_msg->l_start->n_data);
	else
		find_and_run_cmd(stor, hdl, split_msg);
	list_destroy(split_msg);
}
