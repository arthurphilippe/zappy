/*
** EPITECH PROJECT, 2018
** zappy
** File description:
** Core
*/

#include <chrono>
#include <thread>
#include "Core.hpp"
#include "BackgroundMap.hpp"
#include <SFML/Graphics.hpp>
#include <unistd.h>

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
	auto pos = _serv.getMapSize();
	BackgroundMap beck(pos.x, pos.y);
	auto map = beck.getMap();
	while (_display.isRunning()) {
		_display.clear();
		_serv.getHints();
		std::cout << _serv.getPlayerList().size() << std::endl;
		_serv.processCmd();
		_display.putItem(map);
		_display.refresh();
		sleep(1);
	}
	return (true);
}
}
