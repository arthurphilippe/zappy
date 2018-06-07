/*
** EPITECH PROJECT, 2018
** PSU_zappy_2017
** File description:
** client
*/

#include <criterion/criterion.h>
#include <criterion/assert.h>
#include "selector.h"
#include "player.h"

size_t client_fill_player_queue(player_t *pl, const char *buf);

Test(HandleClient, FillPlayerQueue)
{
	player_t *pl = player_create();

	client_fill_player_queue(pl, "voiture de police\r\n"
		"parlement europeen\r\n");
	cr_assert_eq(pl->p_queued_msgs->l_size, 2);
	client_fill_player_queue(pl, "epitech nantes\r\n"
		"champinat de ping-gong\r\n"
		"on dit tenis de table malautru\n");
	cr_assert_eq(pl->p_queued_msgs->l_size, 5);
}

Test(HandleClient, FillPlayerQueueOverflow)
{
	player_t *pl = player_create();

	client_fill_player_queue(NULL, NULL);
	client_fill_player_queue(pl, "voiture de police\r\n"
		"parlement europeen\r\n");
	client_fill_player_queue(pl, "epitech nantes\r\n"
		"champinat de ping-gong\r\n"
		"on dit tenis de table malautru\n");
	client_fill_player_queue(pl, "voiture de police\r\n"
		"parlement europeen\r\n");
	client_fill_player_queue(pl, "epitech nantes\r\n"
		"champinat de ping-gong\r\n"
		"on dit tenis de table malautru\n");
	client_fill_player_queue(pl, "voiture de police\r\n"
		"parlement europeen\r\n");
	client_fill_player_queue(pl, "epitech nantes\r\n"
		"champinat de ping-gong\r\n"
		"on dit tenis de table malautru\n");
	client_fill_player_queue(pl, "voiture de police\r\n"
		"parlement europeen\r\n");
	client_fill_player_queue(pl, "epitech nantes\r\n"
		"champinat de ping-gong\r\n"
		"on dit tenis de table malautru\n");
	cr_assert_eq(pl->p_queued_msgs->l_size, 10);
}

