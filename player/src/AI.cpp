/*
** EPITECH PROJECT, 2018
** zappy
** File description:
** Client's AI
*/

#include "AI.hpp"

namespace pl {

AI::AI()
	: _stratLevel(LAUNCH_ELEVATION), _elevationLevel(0), _status(false)
{}

AI::~AI()
{}

void AI::initStrats(Socket &socket)
{
	std::unique_ptr<IStrat> def(new DefaultStrat(socket));
	std::unique_ptr<IStrat> focus(new FocusStrat(socket));
	std::unique_ptr<IStrat> goToElev(new GoToElevationStrat(socket));
	std::unique_ptr<IStrat> launchElev(new
		LaunchElevationStrat(socket, _elevationLevel));
	_strats.push_back(std::move(def));
	_strats.push_back(std::move(focus));
	_strats.push_back(std::move(goToElev));
	_strats.push_back(std::move(launchElev));
}

void AI::look(Socket &socket, const Processing &processing)
{
	std::string reply;

	this->clearVision();
	socket << "Look\n";
	while (!socket.tryToRead(reply));
	if (processing.catchMessage(reply))
		_stratLevel = GO_TO_ELEVATION;
	else
		processing.vision(reply, _vision);
}

void AI::lookAtInventory(Socket &socket, const Processing &processing)
{
	std::string reply;

	this->clearInventory();
	socket << "Inventory\n";
	while (!socket.tryToRead(reply));
	std::cout << "Inventory: "<< reply <<std::endl;
	try {
		if (processing.catchMessage(reply))
			_stratLevel = GO_TO_ELEVATION;
		else
			processing.inventory(reply, _inventory);
	} catch (std::exception &err) {
		std::cerr << "Error while looking at inventory" << std::endl;
	}
}

void AI::clearVision()
{
	for (auto &tile : _vision)
		tile.clear();
	_vision.clear();
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

void AI::executeStrat(Socket &_socket, const Processing &processing) noexcept
{
	std::string reply;
	_strats[_stratLevel]->run(_vision);
	while (!_socket.tryToRead(reply));
	if (processing.catchMessage(reply))
		_stratLevel = GO_TO_ELEVATION;
	_status = _strats[_stratLevel]->isRuning();
	std::cout << _elevationLevel << std::endl;
}

}
