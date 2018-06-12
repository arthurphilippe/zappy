/*
** EPITECH PROJECT, 2018
** PSU_zappy_2017
** File description:
** reset
*/

#include <stdlib.h>
#include "dynbuf.h"

int dynbuf_reset(dynbuf_t *buf)
{
	free(buf->b_data);
	buf->b_data = malloc(sizeof(char) * BUF_SIZE);
	if (!buf->b_data) {
		free(buf);
		return (-1);
	}
	buf->b_data[0] = '\0';
	buf->b_allotted = BUF_SIZE;
	buf->b_lengh = 0;
	return (0);
}
