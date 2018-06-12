/*
** EPITECH PROJECT, 2018
** PSU_zappy_2017
** File description:
** egg
*/

#include <unistd.h>
#include <criterion/criterion.h>
#include <criterion/assert.h>
#include "egg.h"

Test(Egg, all)
{
	egg_t *egg = egg_create("pandas", (vector2d_t){2, 3}, 12000);

	cr_assert(egg);
	cr_assert_eq(egg_has_hatched(egg), false);
	usleep(60000);
	cr_assert_eq(egg_has_hatched(egg), true);
	cr_assert_str_eq(egg->eg_team_name, "pandas");
	cr_assert_eq(egg->eg_pos.v_x, 2);
	cr_assert_eq(egg->eg_pos.v_y, 3);
	cr_assert_eq(egg_has_hatched(egg), true);
}
