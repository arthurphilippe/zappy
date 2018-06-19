/*
** EPITECH PROJECT, 2018
** server
** File description:
** heading
*/

#include <criterion/assert.h>
#include <criterion/criterion.h>
#include "heading.h"

Test(Heading, get) {
	cr_expect_eq(heading_get_code((vector2d_t){62, 0}), 0);
	cr_expect_eq(heading_get_code((vector2d_t){-1, 0}), WEST);
	cr_expect_eq(heading_get_code((vector2d_t){1, 0}), EAST);
	cr_expect_eq(heading_get_code((vector2d_t){0, 1}), SOUTH);
}
