/*
** EPITECH PROJECT, 2018
** zappy
** File description:
** Core
*/

#include "Core.hpp"

namespace gi {

Core::Core(int ac, char **av)
	: _serv(ac, av)
{
}

Core::~Core()
{
}

bool Core::loop()
{
	while (_display.isRunning()) {
	}
	return (true);
}


}
