/*
** EPITECH PROJECT, 2018
** PSU_zappy_2017
** File description:
** main
*/

#include <stdlib.h>
#include <stdio.h>
#include "selector.h"

int main(int ac, char **av)
{
	selector_t *stor;

	if (ac < 2) {
		dprintf(2, "To few arguments.\n");
		return (84);
	}
	stor = selector_create();

	if (listener_create(stor, atoi(av[1]))) {
		perror("listener");
		selector_delete(stor);
		return (84);
	}
	selector_loop(stor);
	selector_delete(stor);
	printf("salut.\n");
}
