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
	chrono_t *ch = chrono_create(50);

	cr_assert_eq(chrono_check(ch), CHRONO_VALID);
	cr_assert_eq(chrono_check(ch), CHRONO_VALID);
	cr_assert_eq(chrono_check(ch), CHRONO_VALID);
	cr_assert_eq(chrono_check(ch), CHRONO_VALID);
	usleep(50000);
	cr_assert_eq(chrono_check(ch), CHRONO_EXPIRED);
}

Test(Chrono, short_duration_two) {
	chrono_t *ch = chrono_create(5);

	cr_assert_eq(chrono_check(ch), CHRONO_VALID);
	cr_assert_eq(chrono_check(ch), CHRONO_VALID);
	cr_assert_eq(chrono_check(ch), CHRONO_VALID);
	cr_assert_eq(chrono_check(ch), CHRONO_VALID);
	usleep(5000);
	cr_assert_eq(chrono_check(ch), CHRONO_EXPIRED);
}

Test(Chrono, long_duration) {
	chrono_t *ch = chrono_create(500);

	cr_assert_eq(chrono_check(ch), CHRONO_VALID);
	cr_assert_eq(chrono_check(ch), CHRONO_VALID);
	cr_assert_eq(chrono_check(ch), CHRONO_VALID);
	usleep(500000);
	cr_assert_eq(chrono_check(ch), CHRONO_EXPIRED);
}


Test(Chrono, time_null) {
	chrono_t *ch = chrono_create(0);

	cr_assert_eq(ch, NULL);
}

