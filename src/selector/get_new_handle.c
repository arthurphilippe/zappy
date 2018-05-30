/*
** EPITECH PROJECT, 2018
** PSU_zappy_2017
** File description:
** get_new_handle
*/

#include <stdlib.h>
#include "selector.h"

handle_t *selector_get_new_handle(selector_t *selector)
{
	handle_t *hdl = malloc(sizeof(handle_t));

	if (!hdl)
		return (NULL);
	if (list_push_back(selector->s_handles, hdl) != LIST_OK) {
		free(hdl);
		return (NULL);
	}
	hdl->h_type = H_FREE;
	return (hdl);
}
