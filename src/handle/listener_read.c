/*
** EPITECH PROJECT, 2018
** PSU_zappy_2017
** File description:
** listener_read
*/

#include <arpa/inet.h>
#include <stdio.h>
#include <sys/socket.h>
#include "selector.h"

/*
** Accepts connecetions on the socket pointed to by the listener.
*/
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
