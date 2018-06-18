/*
** EPITECH PROJECT, 2018
** server
** File description:
** delayed_cmd
*/

#ifndef DELAYED_CMD_H_
	#define DELAYED_CMD_H_

	#include "chrono.h"

typedef struct s_list list_t;
typedef struct s_selector selector_t;
typedef struct s_handle handle_t;

typedef struct		s_delayed_cmd {
	chrono_t	dc_timer;
	list_t		*dc_args;
	void		(*dc_callback)
			(selector_t *stor, handle_t *hdl, list_t *args);
}			delayed_cmd_t;

#endif /* !DELAYED_CMD_H_ */
