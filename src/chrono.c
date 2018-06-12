/*
** EPITECH PROJECT, 2018
** zappy
** File description:
** chrono file
*/

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/time.h>
#include "../include/chrono.h"

void chrono_init(chrono_t *ch)
{
	struct timeval te;
	long long mil;

	gettimeofday(&te, NULL);
	mil = te.tv_sec * 1000 + te.tv_usec/1000;
	ch->c_counter = mil;
}

chrono_t *chrono_create(unsigned int n)
{
	chrono_t *ch = malloc(sizeof(chrono_t));

	if (ch == NULL)
		return NULL;
	ch->c_value = n;
	chrono_init(ch);
	return (ch);
}

bool chrono_check(chrono_t *ch)
{
	struct timeval te;
	long long mil;
	long dif;

	gettimeofday(&te, NULL);
	mil = te.tv_sec * 1000 + te.tv_usec/1000;
	dif = mil - ch->c_counter;
	if (ch->c_value <= dif)
		return (true);
	return (false);
}
