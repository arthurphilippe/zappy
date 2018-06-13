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
#include "msg_cmd_gfx.h"
#include "selector.h"
#include "stolist.h"

const msg_map_t MSG_CMD_GFX_MAP[] = {
	{CMD_GET_MAP_SIZE, msg_cmd_gfx_get_map_size, 0},
	{CMD_GET_TILE_CONTENT, msg_cmd_gfx_get_tile_cont, 0},
	{CMD_GET_MAP_CONTENT, msg_cmd_gfx_get_map_cont, 0},
	{CMD_GET_TEAM_NAMES, NULL, 0},
	{CMD_GET_PLAYER_POS, NULL, 0},
	{CMD_GET_PLAYER_LEVEL, NULL, 0},
	{CMD_GET_PLAYER_INV, NULL, 0},
	{CMD_GET_FREQ, NULL, 0},
	{CMD_SET_FREQ, NULL, 0},
	{NULL, NULL, 0},
};

void msg_process_cmd_gfx(selector_t *stor, handle_t *hdl, list_t *msg)
{
	char *cmd_name;

	if (!msg || !msg->l_size)
		return;
	cmd_name = msg->l_start->n_data;
	for (unsigned int i = 0; MSG_CMD_GFX_MAP[i].mm_name; i++) {
		if (!strcasecmp(cmd_name, MSG_CMD_GFX_MAP[i].mm_name) &&
			MSG_CMD_GFX_MAP[i].mm_func) {
			list_pop_front(msg);
			MSG_CMD_GFX_MAP[i].mm_func(stor, hdl, msg);
			return;
		}
	}
}
