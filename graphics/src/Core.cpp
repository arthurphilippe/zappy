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
	BackgroundMap backMap(pos.x, pos.y);
	_serv.setMap(backMap.getMap());
	auto &map = _serv.getMap();
	while (_display.isRunning()) {
		_display.clear();
		_serv.updateMap();
		_serv.updatePlayer();
		_serv.getHints();
		_serv.processCmd();
		_display.putItem(map);
		_display.putPlayer(_serv.getPlayerList());
		_display.putIncant(_serv.getIncatPos());
		_display.refresh();
	}
	return (true);
}
}
