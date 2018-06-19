/*
** EPITECH PROJECT, 2018
** Zappy
** File description:
** Created by hexa,
*/

#include <stdlib.h>
#include <time.h>

int random_int(int min, int max)
{
	int rvalue = min - 1;
	struct timespec ts;

	while (rvalue < min) {
		clock_gettime(CLOCK_MONOTONIC, &ts);
		srand((unsigned int) ts.tv_nsec);
		rvalue = rand() % (max + 1);
	}
	return (rvalue);
}
