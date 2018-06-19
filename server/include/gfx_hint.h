/*
** EPITECH PROJECT, 2018
** server
** File description:
** gfx_hint
*/

#ifndef GFX_HINT_H_
	#define GFX_HINT_H_

typedef struct	s_player player_t;
typedef struct	s_egg egg_t;

void gfx_hint_init(int fd);
int gfx_hint_get_fd(void);

void gfx_hint_pnw(player_t *pl);
void gfx_hint_pex(player_t *pl);
void gfx_hint_enw(player_t *pl, egg_t *egg);

#endif /* !GFX_HINT_H_ */
