/*
** EPITECH PROJECT, 2018
** server
** File description:
** incantation
*/

#include <stdio.h>
#include "msg.h"
#include "player.h"
#include "player_rite.h"
#include "gfx_hint.h"

void msg_cmd_pl_incentation_callback(
	selector_t *stor, handle_t *hdl, list_t *args)
{
	list_iter_t iter;
	player_t *pl;

	(void) stor;
	(void) hdl;
	gfx_hint_pie(hdl->h_data);
	list_iter_init(&iter, args, FWD);
	while ((pl = list_iter_next(&iter))) {
		pl->p_lvl += 1;
	}
}

static void check_pos_and_set_callback(
	player_t *pl1, player_t *pl2, list_t *args, int fd)
{
	if (pl1->p_pos.v_x == pl2->p_pos.v_x &&
		pl1->p_pos.v_y == pl2->p_pos.v_y) {
		list_push_back(args, pl2);
		dprintf(fd, "Elevation underway Current level: %d\n",
			pl2->p_lvl);
	}
}

static void search_handles(selector_t *stor, player_t *pl, list_t *args)
{
	list_iter_t iter;
	handle_t *hdl;

	list_iter_init(&iter, stor->s_handles, FWD);
	while ((hdl = list_iter_next(&iter))) {
		if (hdl->h_type == H_PLAYER) {
			check_pos_and_set_callback(
				pl, hdl->h_data, args, hdl->h_fd);
		}
	}
}

void msg_cmd_pl_incentation(selector_t *stor, handle_t *hdl, list_t *args)
{
	player_t *pl = hdl->h_data;

	while (list_get_size(args))
		list_pop_back(args);
	if (player_rite_check_tile(pl, stor->s_data)) {
		pl->p_task.dc_callback = msg_cmd_pl_incentation_callback;
		chrono_init(&pl->p_task.dc_timer, 300);
		gfx_hint_pic(pl);
		search_handles(stor, pl, args);
	} else
		dprintf(hdl->h_fd, "ko\n");
}
