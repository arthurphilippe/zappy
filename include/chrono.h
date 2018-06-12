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
       	double		c_value;
	long long	c_counter;
}		chrono_t;

void chrono_init(chrono_t *ch);
chrono_t *chrono_create(unsigned int n);
bool chrono_check(chrono_t *ch);

#endif /* !CHRONO_H_ */
