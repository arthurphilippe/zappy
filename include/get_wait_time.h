/*
** EPITECH PROJECT, 2018
** PSU_zappy_2017
** File description:
** get_wait_time
*/

#ifndef GET_WAIT_TIME_H_
	#define GET_WAIT_TIME_H_

static inline unsigned int get_wait_time(unsigned int f, unsigned int w)
{
	return (w / f * 1000);
}

#endif /* !GET_WAIT_TIME_H_ */
