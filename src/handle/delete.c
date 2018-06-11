/*
** EPITECH PROJECT, 2018
** PSU_zappy_2017
** File description:
** delete
*/

#include <stdio.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <unistd.h>
#include "selector.h"

void selector_handle_delete(void *ptr)
{
	handle_t *hdl = ptr;

	if (hdl->h_type == H_PORT) {
		shutdown(hdl->h_fd, SHUT_RDWR);
		close(hdl->h_fd);
	} else if (hdl->h_type == H_PLAYER || hdl->h_type == H_GFX) {
		if (hdl->h_fd > 2) {
			close(hdl->h_fd);
			printf("%d: Connection closed\n", hdl->h_fd);
		}
	}
	if (hdl->h_delete)
		hdl->h_delete(hdl->h_data);
	free(ptr);
}
