/*
** EPITECH PROJECT, 2018
** zappy
** File description:
** broadcast header
*/

#ifndef BROADCAST_H_
	#define BROADCAST_H_

typedef struct s_vector2d vector2d_t;

float calc_prod_s(vector2d_t, vector2d_t, vector2d_t);
float calc_dist(vector2d_t, vector2d_t, vector2d_t);
int get_value(float);
int broacast_get_prior_tile(
	vector2d_t send, vector2d_t receive, vector2d_t dir);

#endif /* !BROADCAST_H_ */
