/*
** EPITECH PROJECT, 2018
** zappy
** File description:
** AI's launch elevation strategy
*/

#include "LaunchElevationStrat.hpp"

namespace pl {

LaunchElevationStrat::LaunchElevationStrat(Socket &socket,
	int &elevationLevel)
	: _status(false), _elevationLevel(elevationLevel),
		_socket(socket), _isElevated(false)
{}

LaunchElevationStrat::~LaunchElevationStrat()
{}

void LaunchElevationStrat::run(std::vector<std::vector<std::string>> &vision)
	noexcept
{
	if (!_isElevated) {
		_socket << "Broadcast zappy-cléfèss\n";
		checkForPlayers(vision);
	}
	else
		_socket << "Broadcast zappy-mendésspeulète\n";
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
	if (nbOfPlayersOnMe >= nbOfPlayerNeeded()) {
		_socket << "Incantation\n";
		_isElevated = true;
	}
}

}