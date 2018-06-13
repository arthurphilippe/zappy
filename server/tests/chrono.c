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

	cr_expect_eq(chrono_check(ch), CHRONO_RUNNING);
	cr_expect_eq(chrono_check(ch), CHRONO_RUNNING);
	cr_expect_eq(chrono_check(ch), CHRONO_RUNNING);
	cr_expect_eq(chrono_check(ch), CHRONO_RUNNING);
	usleep(60000);
	cr_expect_eq(chrono_check(ch), CHRONO_EXPIRED);
}

Test(Chrono, short_duration_two) {
	chrono_t *ch = chrono_create(5);

	cr_expect_eq(chrono_check(ch), CHRONO_RUNNING);
	cr_expect_eq(chrono_check(ch), CHRONO_RUNNING);
	cr_expect_eq(chrono_check(ch), CHRONO_RUNNING);
	cr_expect_eq(chrono_check(ch), CHRONO_RUNNING);
	usleep(5500);
	cr_expect_eq(chrono_check(ch), CHRONO_EXPIRED);
}

Test(Chrono, time_null) {
	chrono_t *ch = chrono_create(0);

	cr_expect_eq(ch, NULL);
}

