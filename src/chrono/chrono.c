/*
** EPITECH PROJECT, 2018
** zappy
** File description:
** chrono file
*/

#include <stdlib.h>
#include <stdbool.h>
#include "chrono.h"

void chrono_init(chrono_t *ch, unsigned int n)
{
	ch->c_counter = clock();
}

chrono_t *chrono_create(unsigned int n)
{
	ch = malloc(sizeof(chrono_t));

	if (ch == NULL)
		return NULL;
	ch->c_value = (double)n;
	return (chrono_init(ch, n));
}

bool chrono_check(chrono_t *ch)
{
	clock_t f = clock();
	double now = (double)((double)(f)/ CLOCKS_PER_SEC);
	double first = (double)((double)(ch->c_counter)/CLOCKS_PER_SEC);
	double dif = (now - first) * 1000;

	if (ch->c_value <= dif)
		return (true);
	return (false);
}
