/*
** EPITECH PROJECT, 2018
** zappy
** File description:
** Client's AI
*/

#include "AI.hpp"

namespace pl {

AI::AI()
{}

void AI::look(Socket &socket, const Processing &processing)
{
	std::string reply;

	this->clearVision();
	socket << "Look";
	while (!socket.tryToRead(reply));
	processing.vision(reply, _vision);
}

void AI::lookAtInventory(Socket &socket, const Processing &processing)
{
	std::string reply;

	this->clearInventory();
	socket << "Inventory";
	while (!socket.tryToRead(reply));
	try {
		processing.inventory(reply, _inventory);
	} catch (std::exception &err) {
		std::cerr << "Error while looking at inventory";
	}
}

void AI::clearVision()
{
	while (!_vision.empty()) {
		_vision.pop_back();
	}
}

void AI::clearInventory()
{
	_inventory["food"] = 0;
	_inventory["linemate"] = 0;
	_inventory["deraumere"] = 0;
	_inventory["sibur"] = 0;
	_inventory["mendiane"] = 0;
	_inventory["phiras"] = 0;
	_inventory["thystame"] = 0;
}

}