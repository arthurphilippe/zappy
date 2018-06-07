/*
** EPITECH PROJECT, 2018
** PSU_zappy_2017
** File description:
** client_create
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "player.h"
#include "selector.h"

int client_create(selector_t *stor, int sock)
{
	handle_t *hdl = selector_get_new_handle(stor);

	if (!hdl) {
		close(sock);
		return (SELECTOR_RET_ERR);
	}
	hdl->h_data = player_create();
	if (!hdl->h_data) {
		close(sock);
		list_find_and_delete_addr(stor->s_handles, hdl);
		return (SELECTOR_RET_ERR);
	}
	hdl->h_fd = sock;
	hdl->h_type = H_CLIENT;
	hdl->h_read = client_read;
	hdl->h_on_cycle = client_on_cycle;
	dprintf(sock, "%s\n", "WELCOME");
	return (SELECTOR_RET_OK);
}
