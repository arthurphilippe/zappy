/*
** EPITECH PROJECT, 2018
** PSU_zappy_2017
** File description:
** append
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "dynbuf.h"

void dynbuf_append_str(dynbuf_t *buf, const char *str)
{
	size_t lengh = strlen(str);

	buf->b_lengh += lengh;
	if (lengh + buf->b_lengh >= buf->b_allotted) {
		buf->b_allotted = buf->b_lengh;
		dynbuf_complete_size(&buf->b_allotted);
		buf->b_data = realloc(buf->b_data, buf->b_allotted);
	}
	strcat(buf->b_data, str);
}

void dynbuf_append_int(dynbuf_t *buf, int val)
{
	char tmp[15];

	snprintf(tmp, 15, "%d", val);
	dynbuf_append_str(buf, tmp);
}

void dynbuf_append_uint(dynbuf_t *buf, unsigned int val)
{
	char tmp[15];

	snprintf(tmp, 15, "%d", val);
	dynbuf_append_str(buf, tmp);
}
