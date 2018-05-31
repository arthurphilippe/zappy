/*
** EPITECH PROJECT, 2018
** PSU_zappy_2017
** File description:
** client_delete
*/

#include <stdio.h>
#include <unistd.h>
#include "selector.h"

void client_delete(selector_t *stor, handle_t *hdl)
{
	if (hdl->h_fd > 2) {
		printf("%d: Connection closed\n", hdl->h_fd);
		close(hdl->h_fd);
	}
	list_find_and_delete_addr(stor->s_handles, hdl);
	stor->s_live = false;
}
