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

	if (!buf || dynbuf_init(buf) != 0)
		return (NULL);
	return (buf);
}
