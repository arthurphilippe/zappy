/*
** EPITECH PROJECT, 2018
** PSU_zappy_2017
** File description:
** listener_read
*/

#include <stdio.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include "selector.h"

void listener_read(selector_t *selector, handle_t *port_hdl)
{
	int socket;
	struct sockaddr_in sin;
	socklen_t sin_len = sizeof(sin);

	socket = accept(port_hdl->h_fd, (struct sockaddr *) &sin, &sin_len);
	if (socket == -1)
		return;
	printf("%d\n", client_create(selector, socket));
}
