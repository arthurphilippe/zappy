/*
** EPITECH PROJECT, 2018
** PSU_zappy_2017
** File description:
** handle
*/

#ifndef SELECTOR_HANDLE_H_
	#define SELECTOR_HANDLE_H_

typedef enum	e_handle_type {
		H_FREE = 0,
		H_PORT,
		H_PLAYER,
		H_GFX,
		H_SERVER,
		H_STDIN,
}		handle_type_t;

typedef void (*handle_func_t)();

typedef struct		s_handle {
	int		h_fd;
	handle_type_t	h_type;
	handle_func_t	h_read;
	handle_func_t	h_on_cycle;
	void		*h_data;
	void		(*h_delete)(void *ptr);
}			handle_t;

#endif /* !SELECTOR_HANDLE_H_ */
