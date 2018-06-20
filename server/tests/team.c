/*
** EPITECH PROJECT, 2018
** PSU_zappy_2017
** File description:
** team
*/

#include <unistd.h>
#include <criterion/assert.h>
#include <criterion/criterion.h>
#include "team.h"
#include "egg.h"

Test(Team, create)
{
	team_t *tm = team_create("ursidae", 6);

	cr_assert(tm);
	cr_assert_str_eq(tm->t_name, "ursidae");
	cr_assert_eq(tm->t_max_memb, 6);
	team_delete(tm);
}

Test(Team, consume_eggs) {
	team_t *tm1 = team_create("ursidae", 6);
	team_t *tm2 = team_create("findus", 6);
	list_t *eggs = list_create(egg_delete);
	list_t *teams = list_create(team_delete);

	cr_assert(tm1);
	cr_assert_str_eq(tm1->t_name, "ursidae");
	cr_assert_eq(tm1->t_max_memb, 6);
	cr_assert(tm2);
	cr_assert_str_eq(tm2->t_name, "findus");
	cr_assert_eq(tm2->t_max_memb, 6);
	list_push_back(teams, tm1);
	list_push_back(teams, tm2);

	egg_t *egg = egg_create("findus", (vector2d_t) {0, 0}, 100000);
	cr_assert(egg);
	list_push_back(eggs, egg);
	egg = egg_create("findus", (vector2d_t) {0, 0}, 100000);
	cr_assert(egg);
	list_push_back(eggs, egg);
	egg = egg_create("ursidae", (vector2d_t) {0, 0}, 100000);
	cr_assert(egg);
	list_push_back(eggs, egg);
	usleep(10000);
	team_consume_eggs(teams, eggs);
	cr_expect_eq(tm2->t_hatched_eggs->l_size, 2);
	cr_expect_eq(tm2->t_max_memb, 6, "got %d", tm2->t_max_memb);
	cr_expect_eq(tm1->t_hatched_eggs->l_size, 1);
	cr_expect_eq(tm1->t_max_memb, 6);
	egg = egg_create("findus", (vector2d_t) {0, 0}, 1);
	cr_assert(egg);
	list_push_back(eggs, egg);
	team_consume_eggs(teams, eggs);
	cr_expect_eq(tm2->t_max_memb, 6, "got %d", tm2->t_max_memb);
	cr_expect_eq(tm2->t_hatched_eggs->l_size, 2);

	list_destroy(eggs);
	list_destroy(teams);
}
