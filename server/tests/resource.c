/*
** EPITECH PROJECT, 2018
** PSU_zappy_2017
** File description:
** resource
*/

#include <criterion/criterion.h>
#include <criterion/assert.h>
#include "resource.h"

Test(Resource, get_name)
{
	const char *str = resource_get_name(SIBUR);

	cr_assert_str_eq(str, "sibur");
	str = resource_get_name(12);
	cr_assert_str_eq(str, "");
	str = resource_get_name(MENDIANE);
	cr_assert_str_eq(str, "mendiane");
	str = resource_get_name(THYSTAME);
	cr_assert_str_eq(str, "thystame");
}

Test(Resource, get_value)
{
	resource_t tmp;

	tmp = resource_get_value("food");
	cr_expect_eq(tmp, 0);
	tmp = resource_get_value("deraumere");
	cr_expect_eq(tmp, DERAUMERE);
	tmp = resource_get_value("phiras");
	cr_expect_eq(tmp, PHIRAS);
	tmp = resource_get_value("thystame");
	cr_expect_eq(tmp, THYSTAME);
}
