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

	selector_delete(stor);
	printf("salut.\n");
}
