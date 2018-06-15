/*
** EPITECH PROJECT, 2018
** zappy
** File description:
** Client's Core
*/

#include "Core.hpp"

namespace pl {

Core::Core(int ac, char **av)
{
	std::vector<std::string> args;
	for (int i = 1; i < ac; i++) {
		std::string arg = av[i];
		args.push_back(arg);
	}
	if (args.size() != 4 && args.size() != 6)
		throw std::runtime_error("Wrong arguments number");
}

Core::~Core()
{}

}