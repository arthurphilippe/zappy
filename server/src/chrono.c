/*
** EPITECH PROJECT, 2018
** zappy
** File description:
** chrono file
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "chrono.h"
#include "color.h"

void chrono_init(chrono_t *ch, unsigned int n)
{
	gettimeofday(&ch->c_counter, NULL);
	ch->c_value = n * 1000;
	ch->c_expired = (n) ? false : true;
}

chrono_t *chrono_create(unsigned int n)
{
	chrono_t *ch;

	ch = malloc(sizeof(chrono_t));
	if (ch == NULL)
		return (NULL);
	chrono_init(ch, n);
	return (ch);
}

bool chrono_check(chrono_t *ch)
{
	struct timeval te;
	long usec = 0;
	long seconds = 0;

	if (ch->c_expired)
		return (CHRONO_EXPIRED);
	gettimeofday(&te, NULL);
	seconds = te.tv_sec - ch->c_counter.tv_sec;
	seconds = seconds * 1000000;
	usec = te.tv_usec - ch->c_counter.tv_usec;

	if ((usec + seconds) <= ch->c_value)
		return (CHRONO_RUNNING);
	ch->c_expired = true;
	return (CHRONO_EXPIRED);
}
