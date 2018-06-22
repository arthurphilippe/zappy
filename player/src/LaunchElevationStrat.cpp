/*
** EPITECH PROJECT, 2018
** zappy
** File description:
** AI's launch elevation strategy
*/

#include "LaunchElevationStrat.hpp"

namespace pl {

LaunchElevationStrat::LaunchElevationStrat(Socket &socket,
	STRAT &stratLevel, int &elevationLevel,
	std::vector<std::array<int, 6>> &elevation)
	: _status(false), _stratLevel(stratLevel),
		_elevationLevel(elevationLevel),
		_socket(socket), _isElevated(false),
		_elevation(elevation)
{}

LaunchElevationStrat::~LaunchElevationStrat()
{}

void LaunchElevationStrat::run(std::vector<std::vector<std::string>> &vision)
	noexcept
{
	if (!_isElevated) {
		std::string toSend = "Broadcast Come:";
		toSend += _elevationLevel;
		toSend += "\n";
		_socket << toSend;
		checkForPlayers(vision);
	}
	else {
		_socket << "Broadcast Stop\n";
		_stratLevel = DEFAULT;
	}
}

void LaunchElevationStrat::checkForPlayers(std::vector<std::vector<std::string>>
	&vision) noexcept
{
	int nbOfPlayersOnMe = 0;
	auto &tile = vision[0];

	for (auto &item : tile) {
		if (item == "player")
			nbOfPlayersOnMe++;
	}
	if (nbOfPlayersOnMe >= nbOfPlayersNeeded())
		runIncantation();
}

void LaunchElevationStrat::runIncantation()
{
	std::string stoneToDrop;
	for (int i = 0; i < 6; i++) {
		for (int j = 0; j < _elevation[_elevationLevel][i]; j++) {
			stoneToDrop = "Set ";
			stoneToDrop += getStoneName(i);
			stoneToDrop += "\n";
			_socket << stoneToDrop;
		}
	}
	_socket << "Incantation\n";
	_elevationLevel++;
	_isElevated = true;
}

std::string LaunchElevationStrat::getStoneName(int i) const
{
	switch (i) {
		case 0:
			return "linemate";
		case 1:
			return "deraumere";
		case 2:
			return "sibur";
		case 3:
			return "mendiane";
		case 4:
			return "phiras";
		default:
			return "thystame";
	}
}

int LaunchElevationStrat::nbOfPlayersNeeded()
{
	switch (_elevationLevel) {
		case 0:
			return 1;
		case 1: case 2:
			return 2;
		case 3: case 4:
			return 4;
		case 5: case 6:
			return 6;
		default:
			return 0;
	}
}

}