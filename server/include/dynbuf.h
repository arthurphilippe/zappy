/*
** EPITECH PROJECT, 2018
** PSU_zappy_2017
** File description:
** dynbuf
*/

#ifndef DYNBUF_H_
	#define DYNBUF_H_

	#include <stddef.h>

	#define BUF_SIZE 512

/*
** Dynbuf is short for dynamic buffer. It provides a buffer where you can
** append printable strings together for later use.
*/

typedef struct	s_dynbuf {
	char	*b_data;
	size_t	b_allotted;
	size_t	b_lengh;
}		dynbuf_t;

static inline void dynbuf_complete_size(size_t *size)
{
	*size += BUF_SIZE - (*size % BUF_SIZE);
}

dynbuf_t *dynbuf_create(void);
void dynbuf_append_str(dynbuf_t *buf, const char *str);
void dynbuf_append_uint(dynbuf_t *buf, unsigned int val);
void dynbuf_append_int(dynbuf_t *buf, int val);
void dynbuf_delete(void *ptr);
int dynbuf_reset(dynbuf_t *buf);
int dynbuf_init(dynbuf_t *buf);

#endif /* !DYNBUF_H_ */
