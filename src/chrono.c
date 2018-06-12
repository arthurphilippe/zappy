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
#include "color.h"
#include "chrono.h"

void chrono_init(chrono_t *ch)
{
	struct timeval te;
	long long mil;

	gettimeofday(&te, NULL);
	mil = te.tv_usec;
	ch->c_counter = mil;
}

chrono_t *chrono_create(unsigned int n)
{
	chrono_t *ch = malloc(sizeof(chrono_t));

	if (ch == NULL || n == 0)
		return NULL;
	ch->c_value = n * 1000;
	chrono_init(ch);
	return (ch);
}

bool chrono_check(chrono_t *ch)
{
	struct timeval te;
	long long mil;
	long dif;

	gettimeofday(&te, NULL);
	mil = te.tv_usec;
	dif = mil - ch->c_counter;
  	if (dif <= ch->c_value)
		return (CHRONO_RUNNING);
	return (CHRONO_EXPIRED);
}
