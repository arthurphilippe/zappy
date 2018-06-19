/*
** EPITECH PROJECT, 2018
** zappy
** File description:
** broadcast
*/

#include <math.h>
#include <stdlib.h>
#include "vector2d.h"

static float calc_prod_s(vector2d_t pt, vector2d_t pt2, vector2d_t height)
{
	vector2d_t pt_pt2 = {pt2.v_x - pt.v_x, pt2.v_y - pt.v_y};
	vector2d_t pt_height = {height.v_x - pt.v_x, height.v_y - pt.v_y};
	float prod_s =
		(pt_pt2.v_x * pt_height.v_x) + (pt_pt2.v_y * pt_height.v_y);

	return (prod_s);
}

static float calc_dist(vector2d_t pt, vector2d_t pt2, vector2d_t height)
{
	float dist = sqrt(abs(pow(pt2.v_x - pt.v_x, 2)) +
		abs(pow(pt2.v_y - pt.v_y, 2)));
	float dist2 = sqrt(abs(pow(height.v_x - pt.v_x, 2)) +
		abs(pow(height.v_y - pt.v_y, 2)));

	return (dist * dist2);
}

static int get_prior_tile_idx(float angle)
{
	switch ((int) angle) {
	case 0 ... 23:
	case 338 ... 360:
		return (1);
	case 24 ... 67:
		return (2);
	case 68 ... 112:
		return (3);
	case 113 ... 157:
		return (4);
	case 158 ... 202:
		return (5);
	case 203 ... 247:
		return (6);
	case 248 ... 292:
		return (7);
	case 293 ... 337:
		return (8);
	}
	return (0);
}

int broacast_get_prior_tile(
	vector2d_t send, vector2d_t receive, vector2d_t dir)
{
	vector2d_t height = {receive.v_x + dir.v_x, receive.v_y + dir.v_y};
	float dist = calc_dist(receive, send, height);
	float prod_s = calc_prod_s(receive, send, height);
	float angle = acos(prod_s / dist) * 180 / M_PI;

	if (send.v_x - receive.v_x < 0)
		angle = 360 - angle;
	return (get_prior_tile_idx(angle));
}
