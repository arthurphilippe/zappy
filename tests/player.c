/*
** EPITECH PROJECT, 2018
** PSU_zappy_2017
** File description:
** player
*/

#include <criterion/criterion.h>
#include <criterion/assert.h>
#include "player.h"

Test(Player, create)
{
	player_t *pl = player_create("ursidae", "localhost");

	cr_assert(pl);
	cr_assert_str_eq(pl->p_hostname, "localhost");
	cr_assert_str_eq(pl->p_teamname, "ursidae");
	cr_assert_eq(pl->p_id, 1);
	player_delete(pl);
}

Test(Player, id)
{
	player_t *pl = player_create("ursidae", "localhost");

	cr_assert(pl);
	cr_assert_str_eq(pl->p_hostname, "localhost");
	cr_assert_str_eq(pl->p_teamname, "ursidae");
	cr_assert_eq(pl->p_id, 1);
	player_delete(pl);
	pl = player_create("ursidae", "localhost");
	cr_assert_eq(pl->p_id, 2);
	player_delete(pl);
	pl = player_create("ursidae", "localhost");
	cr_assert_eq(pl->p_id, 3);
	player_delete(pl);
	pl = player_create("ursidae", "localhost");
	cr_assert_eq(pl->p_id, 4);
	player_delete(pl);
}
