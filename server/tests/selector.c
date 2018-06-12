/*
** EPITECH PROJECT, 2018
** zappy
** File description:
** selector
*/

#include "selector.h"
#include <criterion/assert.h>
#include <criterion/criterion.h>
#include "game.h"

selector_t *g_selector;

void selector_upon_signal(int signum);

Test(Selector, empty)
{
	selector_t *stor = selector_create();

	cr_expect(stor);
	cr_expect_eq(stor->s_data, NULL);
	cr_expect_eq(stor->s_live, true);
	cr_expect_eq(stor->s_delete, NULL);
	cr_assert_neq(stor->s_handles, NULL);
	cr_expect_eq(stor->s_handles->l_size, 0);
	cr_expect_eq(stor->s_handles->l_destructor, selector_handle_delete);
	cr_expect_eq(g_selector, stor);
	selector_delete(stor);
}

Test(Selector, sig)
{
	selector_t *stor = selector_create();

	cr_expect(stor);
	cr_expect_eq(stor->s_data, NULL);
	cr_expect_eq(stor->s_live, true);
	cr_expect_eq(stor->s_delete, NULL);
	cr_assert_neq(stor->s_handles, NULL);
	cr_expect_eq(stor->s_handles->l_size, 0);
	cr_expect_eq(stor->s_handles->l_destructor, selector_handle_delete);
	cr_expect_eq(g_selector, stor);
	selector_upon_signal(0);
}

Test(Selector, game)
{
	selector_t *stor = selector_create();
	game_t *gm = game_create(20, 15, 1, 6);

	cr_assert(gm);
	cr_assert(stor);
	game_add_team(gm, "pandas");
	stor->s_data = gm;
	stor->s_delete = game_delete;
	selector_delete(stor);
}

Test(Selector, get_handle)
{
	selector_t *stor = selector_create();

	cr_expect(stor);
	cr_expect_eq(stor->s_data, NULL);
	cr_expect_eq(stor->s_live, true);
	cr_expect_eq(stor->s_delete, NULL);
	cr_assert_neq(stor->s_handles, NULL);
	cr_expect_eq(stor->s_handles->l_size, 0);
	cr_expect_eq(stor->s_handles->l_destructor, selector_handle_delete);
	cr_expect_eq(g_selector, stor);
	handle_t *hdl = selector_get_new_handle(stor);

	cr_assert(hdl);
	cr_assert_eq(hdl->h_type, H_FREE);
	selector_delete(stor);
}
