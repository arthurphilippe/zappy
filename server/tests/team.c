/*
** EPITECH PROJECT, 2018
** PSU_zappy_2017
** File description:
** team
*/

#include <criterion/assert.h>
#include <criterion/criterion.h>
#include "team.h"

Test(Team, create)
{
	team_t *tm = team_create("ursidae", 6);

	cr_assert(tm);
	cr_assert_str_eq(tm->t_name, "ursidae");
	cr_assert_eq(tm->t_max_memb, 6);
	team_delete(tm);
}
