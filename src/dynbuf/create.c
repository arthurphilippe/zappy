/*
** EPITECH PROJECT, 2018
** PSU_zappy_2017
** File description:
** dynbuf
*/

#include <stdlib.h>
#include "dynbuf.h"

dynbuf_t *dynbuf_create(void)
{
	dynbuf_t *buf = malloc(sizeof(dynbuf_t));

	if (!buf)
		return (NULL);
	buf->b_data = malloc(sizeof(char) * BUF_SIZE);
	if (!buf) {
		free(buf);
		return (NULL);
	}
	buf->b_data[0] = '\0';
	buf->b_allotted = BUF_SIZE;
	buf->b_lengh = 0;
}
