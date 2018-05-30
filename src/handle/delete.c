/*
** EPITECH PROJECT, 2018
** PSU_zappy_2017
** File description:
** delete
*/

#include <unistd.h>
#include <stdlib.h>
#include <sys/socket.h>
#include "handle.h"

void selector_handle_delete(void *ptr)
{
	handle_t *hdl = ptr;

	if (hdl->h_type == H_PORT) {
		shutdown(hdl->h_fd, SHUT_RDWR);
		close(hdl->h_fd);
	}
	free(ptr);
}
