/*
** EPITECH PROJECT, 2018
** PSU_zappy_2017
** File description:
** player
*/

#ifndef PLAYER_H_
#define PLAYER_H_

typedef struct	s_player {
	int	p_id;
	char	*p_teamname;
	char	*p_hostname;
}		player_t;

player_t *player_create(void);
void player_delete(void *ptr);

#endif /* !PLAYER_H_ */
