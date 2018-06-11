/*
** EPITECH PROJECT, 2018
** PSU_zappy_2017
** File description:
** selector
*/

#ifndef SELECTOR_H_
	#define SELECTOR_H_

	#include <stdbool.h>
	#include "handle.h"
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
** selector prototypes
*/
selector_t *selector_create(void);
void selector_delete(selector_t *);
handle_t *selector_get_new_handle(selector_t *selector);
void selector_loop(selector_t *selector);

/*
** handle prototypes
*/
void selector_handle_delete(void *ptr);

/*
** listener
*/
int listener_create(selector_t *selector, int port);
int listener_create(selector_t *selector, int port);
void listener_read(selector_t *selector, handle_t *port_hdl);

/*
** client handles
*/
int client_create(selector_t *selector, int sock);
void client_erase(selector_t *stor, handle_t *hdl);
void client_read(selector_t *selector, handle_t *client_hdl);
void client_on_cycle(selector_t *stor, handle_t *hdl);
void client_player_buffer_process(handle_t *hdl, char *buf);
list_t *client_get_msgq(handle_t *hdl);

#endif /* !SELECTOR_H_ */
