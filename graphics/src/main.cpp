/*
** EPITECH PROJECT, 2018
** zappy
** File description:
** main
*/

#include "Core.hpp"

int main(int ac, char **av)
{
	gi::Core graphic(ac, av);

	graphic.loop();
}
