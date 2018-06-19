/*
** EPITECH PROJECT, 2018
** PSU_zappy_2017
** File description:
** loop
*/

#include <stdio.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <sys/time.h>
#include <sys/types.h>
#include "selector.h"

static int prepare_for_select(selector_t *selector, fd_set *fd_read)
{
	list_iter_t iter;
	handle_t *hdl;
	int highest_fd = 0;

	list_iter_init(&iter, selector->s_handles, FWD);
	FD_ZERO(fd_read);
	while ((hdl = list_iter_next(&iter))) {
		if (hdl->h_type != H_FREE) {
			FD_SET(hdl->h_fd, fd_read);
			if (highest_fd < hdl->h_fd)
				highest_fd = hdl->h_fd;
		}
	}
	return (highest_fd);
}

static void process_handles(selector_t *stor, fd_set *fd_read)
{
	list_iter_t iter;
	handle_t *hdl;

	list_iter_init(&iter, stor->s_handles, FWD);
	while ((hdl = list_iter_next(&iter))) {
		if (FD_ISSET(hdl->h_fd, fd_read))
			hdl->h_read(stor, hdl);
		if (hdl->h_on_cycle) {
			hdl->h_on_cycle(stor, hdl);
		}
	}
}

static int body(selector_t *selector)
{
	fd_set fd_read;
	int highest_fd = prepare_for_select(selector, &fd_read);
	struct timeval tv;

	tv.tv_sec = 0;
	tv.tv_usec = 1000;
	if (select(highest_fd + 1, &fd_read, NULL, NULL, &tv) == -1) {
		perror("select");
		return (SELECTOR_RET_ERR);
	}
	process_handles(selector, &fd_read);
	if (selector->s_on_cycle)
		selector->s_on_cycle(selector);
	return (SELECTOR_RET_OK);
}

void selector_loop(selector_t *selector)
{
	int ret = 0;

	while (selector->s_live == true && !ret)
		ret = body(selector);
}
