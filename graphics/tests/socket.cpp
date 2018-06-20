/*
** EPITECH PROJECT, 2018
** zappy
** File description:
** socket
*/

#include <criterion/criterion.h>
#include "Socket.hpp"

#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wwrite-strings"

Test(Socket, no_arg)
{
	int ac = 1;
	char *av[1] = {
		"ZappyGi",
	};
	cr_assert_throw(gi::Socket(ac, av), std::runtime_error);
}

Test(Socket, good_ip_port)
{
	int ac = 3;
	char *av[3] = {
		"ZappyGi",
		"ftp.epitech.eu",
		"21",
	};
	cr_assert_no_throw(gi::Socket(ac, av), std::runtime_error);
}

Test(Socket, wrong_ip_good_port)
{
	int ac = 3;
	char *av[3] = {
		"ZappyGi",
		"ftpepitecheu",
		"21",
	};
	cr_assert_throw(gi::Socket(ac, av), std::runtime_error);
}

Test(Socket, good_ip_wrong_port)
{
	int ac = 3;
	char *av[3] = {
		"ZappyGi",
		"ftp.epitech.eu",
		"lol",
	};
	cr_assert_throw(gi::Socket(ac, av), std::invalid_argument);
}
