/*
** EPITECH PROJECT, 2018
** PSU_zappy_2017
** File description:
** main
*/

#include <stdio.h>
#include "selector.h"

int main()
{
	selector_t *stor = selector_create();

	if (listener_create(stor, 4241)) {
		perror("listener");
		selector_delete(stor);
		return (84);
	}
	selector_loop(stor);
	selector_delete(stor);
	printf("salut.\n");
}
