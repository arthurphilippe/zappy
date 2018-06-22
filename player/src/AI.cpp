/*
** EPITECH PROJECT, 2018
** zappy
** File description:
** Client's AI
*/

#include "AI.hpp"

namespace pl {

AI::AI()
	: _stratLevel(DEFAULT), _elevationLevel(0), _status(false)
{
	std::array<int, 6> lvl1 = {1, 0, 0, 0, 0, 0};
	std::array<int, 6> lvl2 = {1, 1, 1, 0, 0, 0};
	std::array<int, 6> lvl3 = {2, 0, 1, 0, 2, 0};
	std::array<int, 6> lvl4 = {1, 1, 2, 0, 1, 0};
	std::array<int, 6> lvl5 = {1, 2, 1, 3, 0, 0};
	std::array<int, 6> lvl6 = {1, 2, 3, 0, 1, 0};
	std::array<int, 6> lvl7 = {2, 2, 2, 2, 2, 1};

	_elevation.push_back(lvl1);
	_elevation.push_back(lvl2);
	_elevation.push_back(lvl3);
	_elevation.push_back(lvl4);
	_elevation.push_back(lvl5);
	_elevation.push_back(lvl6);
	_elevation.push_back(lvl7);
}

AI::~AI()
{}

void AI::initStrats(Socket &socket)
{
	std::unique_ptr<IStrat> def(new DefaultStrat(socket));
	std::unique_ptr<IStrat> focus(new FocusStrat(socket));
	std::unique_ptr<IStrat> goToElev(new
		GoToElevationStrat(socket, _stratLevel, _elevationLevel));
	std::unique_ptr<IStrat> launchElev(new
		LaunchElevationStrat(socket, _stratLevel,
		_elevationLevel, _elevation));
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
	checkElevationPossibility();
	std::string reply;
	_strats[_stratLevel]->run(_vision);
	while (!_socket.tryToRead(reply));
	if (processing.catchMessage(reply))
		_stratLevel = GO_TO_ELEVATION;
	_status = _strats[_stratLevel]->isRuning();
}

void AI::checkElevationPossibility()
{
	if (_inventory["linemate"] >=
		_elevation[_elevationLevel][LINEMATE] &&
		_inventory["deraumere"] >=
		_elevation[_elevationLevel][DERAUMERE] &&
		_inventory["sibur"] >=
		_elevation[_elevationLevel][SIBUR] &&
		_inventory["mendiane"] >=
		_elevation[_elevationLevel][MENDIANE] &&
		_inventory["phiras"] >=
		_elevation[_elevationLevel][PHIRAS] &&
		_inventory["thystame"] >=
		_elevation[_elevationLevel][THYSTAME])
		_stratLevel = LAUNCH_ELEVATION;
}

}
