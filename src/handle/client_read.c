/*
** EPITECH PROJECT, 2018
** PSU_zappy_2017
** File description:
** client_read
*/

#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include "selector.h"

void client_read(selector_t *selector, handle_t *client_hdl)
{
	int r;
	char buf[512];

	r = read(client_hdl->h_fd, buf, 512);
	if (r > 0) {
		buf[r] = '\0';
		printf("%d: %s\n", client_hdl->h_fd, buf);
		// fill_cmd_buff(data, buf);
		if (!strncmp("QUIT", buf, 4))
			client_delete(selector, client_hdl);
		// else
		// 	send_buffed_cmds(selector, client_hdl, data);
	} else {
		client_delete(selector, client_hdl);
	}
}
