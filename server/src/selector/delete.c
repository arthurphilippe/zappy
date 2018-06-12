/*
** EPITECH PROJECT, 2018
** PSU_myirc_2017
** File description:
** delete
*/

#include <stdlib.h>
#include <sys/socket.h>
#include <unistd.h>
#include "selector.h"

void selector_delete(selector_t *selector)
{
	list_destroy(selector->s_handles);
	if (selector->s_delete)
		selector->s_delete(selector->s_data);
	free(selector);
}
