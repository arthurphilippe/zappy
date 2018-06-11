/*
** EPITECH PROJECT, 2018
** zappy
** File description:
** chrono header
*/

#ifndef CHRONO_H_
	#define CHRONO_H_

	#include <time.h>
	#include <stdbool.h>

typedef struct	chrono_s
{
	double	c_value;
	clock_t	c_counter;
}		chrono_t;

void chrono_init(chrono_t *ch, unsigned int n);
chrono_t *chrono_create(unsigned int n);
bool chrono_check(chrono_t *ch);

#endif /* !CHRONO_H_ */
