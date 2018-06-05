/*
** EPITECH PROJECT, 2018
** PSU_zappy_2017
** File description:
** init
*/

#include <stdlib.h>
#include "dynbuf.h"

int dynbuf_init(dynbuf_t *buf)
{
	buf->b_data = malloc(sizeof(char) * BUF_SIZE);
	if (!buf) {
		free(buf);
		return (-1);
	}
	buf->b_data[0] = '\0';
	buf->b_allotted = BUF_SIZE;
	buf->b_lengh = 0;
	return (0);
}
