/*
** EPITECH PROJECT, 2018
** PSU_zappy_2017
** File description:
** create
*/

#include <signal.h>
#include <stdlib.h>
#include "selector.h"

selector_t *g_selector;

static void upon_signal(int signum)
{
	(void) signum;
	selector_delete(g_selector);
	exit(0);
}

selector_t *selector_create(void)
{
	selector_t *selector = malloc(sizeof(selector_t));

	if (!selector)
		return (NULL);
	selector->s_handles = list_create(selector_handle_delete);
	selector->s_data = NULL;
	selector->s_live = true;
	selector->s_delete = NULL;
	g_selector = selector;
	signal(SIGINT, upon_signal);
	return (selector);
}
