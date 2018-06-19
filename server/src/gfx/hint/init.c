/*
** EPITECH PROJECT, 2018
** server
** File description:
** init
*/

#include "gfx_hint.h"

int g_gfx_fd = -1;

void gfx_hint_init(int fd)
{
	g_gfx_fd = fd;
}

int gfx_hint_get_fd(void)
{
	return (g_gfx_fd);
}
