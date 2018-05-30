/*
** EPITECH PROJECT, 2018
** PSU_zappy_2017
** File description:
** client_create
*/

#include <unistd.h>
#include "selector.h"

int client_create(selector_t *selector, int sock)
{
	handle_t *hdl = selector_get_new_handle(selector);

	if (!hdl) {
		close(sock);
		return (SELECTOR_RET_ERR);
	}
	// hdl->h_data = malloc(sizeof(handle_client_t));
	// if (!hdl->h_data) {
	// 	close(sock);
	// 	return (SELECTOR_RET_ERR);
	// }
	// init_data(hdl->h_data);
	hdl->h_fd = sock;
	hdl->h_type = H_CLIENT;
	hdl->h_read = client_read;
	// selector_client_add(selector, hdl);
	return (SELECTOR_RET_OK);
}
