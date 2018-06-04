/*
** EPITECH PROJECT, 2018
** PSU_zappy_2017
** File description:
** msg
*/

#ifndef MSG_H_
	#define MSG_H_

	#include "selector.h"
	#include "list.h"
	#include "player.h"

typedef struct		s_msg_map {
	const char	*mm_name;
	void		(*mm_func)
			(selector_t *stor, handle_t *hdl, list_t *args);
	unsigned int	mm_time_weight;
}			msg_map_t;

void msg_process(selector_t *stor, handle_t *hdl, const char *msg);
void msg_join(selector_t *stor, handle_t *hdl, player_t *pl,
		const char *msg);
void msg_cmd_forward(selector_t *stor, handle_t *hdl, list_t *args);

#endif /* !MSG_H_ */
