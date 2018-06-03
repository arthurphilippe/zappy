/*
** EPITECH PROJECT, 2018
** PSU_zappy_2017
** File description:
** listener_create
*/

#include <arpa/inet.h>
#include <sys/socket.h>
#include <unistd.h>
#include "selector.h"

static int port_bind(int sock, int port)
{
	struct sockaddr_in sin;

	sin.sin_family = AF_INET;
	sin.sin_port = htons(port);
	sin.sin_addr.s_addr = INADDR_ANY;
	return (bind(sock, (struct sockaddr *) &sin, sizeof(sin)));
}

int listener_create(selector_t *selector, int port)
{
	handle_t *hdl = selector_get_new_handle(selector);
	int sock = socket(PF_INET, SOCK_STREAM, 0);

	if (!hdl || sock == -1 || port_bind(sock, port) == -1 ||
		listen(sock, SELECTOR_BACKLOG) == -1) {
		close(sock);
		return (SELECTOR_RET_ERR);
	}
	hdl->h_type = H_PORT;
	hdl->h_fd = sock;
	hdl->h_read = listener_read;
	hdl->h_on_cycle = NULL;
	return (SELECTOR_RET_OK);
}
