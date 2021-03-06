/*
** EPITECH PROJECT, 2018
** server
** File description:
** msg_cmd_gfx
*/

#ifndef MSG_CMD_GFX_H_
	#define MSG_CMD_GFX_H_

	#include "selector.h"

void msg_cmd_gfx_get_map_size(selector_t *stor, handle_t *hdl, list_t *args);
void msg_cmd_gfx_get_tile_cont(selector_t *stor, handle_t *hdl, list_t *args);
void msg_cmd_gfx_get_map_cont(selector_t *stor, handle_t *hdl, list_t *args);
void msg_cmd_gfx_get_team_names(selector_t *stor, handle_t *hdl,
				list_t *args);
void msg_cmd_gfx_get_pl_pos(selector_t *stor, handle_t *hdl, list_t *args);
void msg_cmd_gfx_get_pl_lvl(selector_t *stor, handle_t *hdl, list_t *args);
void msg_cmd_gfx_get_pl_inv(selector_t *stor, handle_t *hdl, list_t *args);
void msg_cmd_gfx_get_freq(selector_t *stor, handle_t *hdl, list_t *args);
void msg_cmd_gfx_set_freq(selector_t *stor, handle_t *hdl, list_t *args);

#endif /* !MSG_CMD_GFX_H_ */
