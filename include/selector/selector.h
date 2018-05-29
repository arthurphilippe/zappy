/*
** EPITECH PROJECT, 2018
** PSU_zappy_2017
** File description:
** selector
*/

#ifndef SELECTOR_H_
	#define SELECTOR_H_

	#include <stdbool.h>
	#include "selector/handle.h"
	#include "list.h"

	#define SELECTOR_RET_OK 0
	#define SELECTOR_RET_ERR -1
	#define SELECTOR_BACKLOG 42
	#ifndef NULL
		#define NULL (void *) 0
	#endif

/*
** data types
*/
typedef enum	e_selector_mode {
		UNK,
		SERVER,
		CLIENT,
}		selector_mode_t;

typedef struct		s_selector {
	list_t		*s_handles;
	void		*s_data;
	selector_mode_t	s_mode;
	bool		s_live;
	void		(*s_delete)();
}			selector_t;

/*
** prototypes
*/
selector_t *selector_create(void);
void selector_delete(selector_t *);

#endif /* !SELECTOR_H_ */
