/*
** EPITECH PROJECT, 2018
** PSU_zappy_2017
** File description:
** delete
*/

#include <stdlib.h>
#include "dynbuf.h"

void dynbuf_delete(void *ptr)
{
	dynbuf_t *buf = ptr;

	free(buf->b_data);
	free(buf);
}
