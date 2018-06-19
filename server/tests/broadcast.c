/*
** EPITECH PROJECT, 2018
** zappy
** File description:
** broadcast
*/

#include <criterion/criterion.h>
#include <criterion/assert.h>
#include "broadcast.h"
#include "vector2d.h"

Test(Broadcast, botleft)
{
	vector2d_t send = {0, 0};
	vector2d_t receive = {2, 4};
	vector2d_t dir = {0, 1};
	cr_expect_eq(calc_broadcast(send, receive, dir), 6);
}

Test(Broadcast, botright)
{
	vector2d_t send = {0, 0};
	vector2d_t receive = {-2, 4};
	vector2d_t dir = {1, 0};
	cr_expect_eq(calc_broadcast(send, receive, dir), 2);
}

Test(Broadcast, topleft)
{
	vector2d_t send = {-2, 4};
	vector2d_t receive = {0, 0};
	vector2d_t dir = {-1, 0};
	cr_expect_eq(calc_broadcast(send, receive, dir), 8);
}

Test(Broadcast, topright)
{
	vector2d_t send = {2, 4};
	vector2d_t receive = {0, 0};
	vector2d_t dir = {0, 1};
	cr_expect_eq(calc_broadcast(send, receive, dir), 2);
}

Test(Broadcast, same_x)
{
	vector2d_t send = {0, 12};
	vector2d_t receive = {0, 1};
	vector2d_t dir = {0, -1};
	cr_expect_eq(calc_broadcast(send, receive, dir), 5);
}

Test(Broadcast, same_y)
{
	vector2d_t send = {14, 1};
	vector2d_t receive = {12, 1};
	vector2d_t dir = {1, 0};
	cr_expect_eq(calc_broadcast(send, receive, dir), 1);
}
