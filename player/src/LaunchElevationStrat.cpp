/*
** EPITECH PROJECT, 2018
** zappy
** File description:
** AI's launch elevation strategy
*/

#include "LaunchElevationStrat.hpp"

namespace pl {

LaunchElevationStrat::LaunchElevationStrat(Socket &socket,
	STRAT &stratLevel, int &elevationLevel)
	: _status(false), _stratLevel(stratLevel),
		_elevationLevel(elevationLevel),
		_socket(socket), _isElevated(false)
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
	if (nbOfPlayersOnMe >= nbOfPlayersNeeded()) {
		_socket << "Incantation\n";
		_isElevated = true;
	}
}

int LaunchElevationStrat::nbOfPlayersNeeded()
{
	switch (_elevationLevel) {
		case 1:
			return 1;
		case 2: case 3:
			return 2;
		case 4: case 5:
			return 4;
		case 6: case 7:
			return 6;
		default:
			return 0;
	}
}

}