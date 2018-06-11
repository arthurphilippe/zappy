/*
** EPITECH PROJECT, 2018
** PSU_zappy_2017
** File description:
** chrono
*/

#include <criterion/criterion.h>
#include <criterion/assert.h>
#include <unistd.h>
#include "chrono.h"

Test(Chrono, short_duration) {
	chrono_t *ch = chrono_create(10);

	cr_assert_eq(chrono_check(ch), false);
	usleep(50000);
	cr_assert_eq(chrono_check(ch), true);
}
