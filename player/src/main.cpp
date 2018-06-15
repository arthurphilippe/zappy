/*
** EPITECH PROJECT, 2018
** zappy
** File description:
** player's main
*/

#include <iostream>
#include "Core.hpp"

int main(int ac, char **av)
{
	try {
		pl::Core core(ac, av);
	} catch (std::exception &err) {
		std::cerr << "ERROR: "<< err.what() << std::endl;
		return 84;
	}
	return 0;
}