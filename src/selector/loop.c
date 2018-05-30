/*
** EPITECH PROJECT, 2018
** PSU_zappy_2017
** File description:
** loop
*/

#include <stdlib.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <sys/time.h>
#include <stdio.h>
#include "selector.h"

static int prepare_for_select(selector_t *selector, fd_set *fd_read)
{
	list_iter_t *iter = list_iter_create(selector->s_handles, FWD);
	handle_t *hdl;
	int highest_fd = 0;

	FD_ZERO(fd_read);
	if (!iter)
		return (-1);
	while ((hdl = list_iter_next(iter))) {
		if (hdl->h_type != H_FREE) {
			FD_SET(hdl->h_fd, fd_read);
			if (highest_fd < hdl->h_fd)
				highest_fd = hdl->h_fd;
		}
	}
	free(iter);
	return (highest_fd);
}

static void read_on_set_fd(selector_t *sv, fd_set *fd_read)
{
	list_iter_t *iter = list_iter_create(sv->s_handles, FWD);
	handle_t *hdl;

	if (!iter)
		return;
	while ((hdl = list_iter_next(iter))) {
		if (FD_ISSET(hdl->h_fd, fd_read))
			hdl->h_read(sv, hdl);
	}
	free(iter);
}

static int body(selector_t *selector)
{
	fd_set fd_read;
	int highest_fd = prepare_for_select(selector, &fd_read);
	struct timeval tv;

	tv.tv_sec = 1;
	tv.tv_usec = 0;
	if (select(highest_fd + 1, &fd_read, NULL, NULL, &tv) == -1) {
		perror("select");
		return (SELECTOR_RET_ERR);
	}
	read_on_set_fd(selector, &fd_read);
	return (SELECTOR_RET_OK);
}

void selector_loop(selector_t *selector)
{
	while (!body(selector) && selector->s_live == true);
}
