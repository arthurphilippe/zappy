/*
** EPITECH PROJECT, 2018
** zappy
** File description:
** chrono header
*/

#ifndef CHRONO_H_
	#define CHRONO_H_

	#include <stdbool.h>
	#include <time.h>
	#include <sys/time.h>

	#define CHRONO_EXPIRED true
	#define CHRONO_RUNNING false

typedef struct		chrono_s
{
	double		c_value;
	struct timeval	c_counter;
	bool		c_expired;
}			chrono_t;

void chrono_init(chrono_t *ch);
chrono_t *chrono_create(unsigned int n);
bool chrono_check(chrono_t *ch);

#endif /* !CHRONO_H_ */
