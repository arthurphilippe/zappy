/*
** EPITECH PROJECT, 2018
** zappy
** File description:
** AI's GoToElevation strat
*/

#include "GoToElevationStrat.hpp"

namespace pl {

GoToElevationStrat::GoToElevationStrat(Socket &socket,
	STRAT &stratLevel, int &elevationLevel)
	: _status(false), _socket(socket), _direction(1),
		_stratLevel(stratLevel), _elevationLevel(elevationLevel)
{}

GoToElevationStrat::~GoToElevationStrat()
{}

void GoToElevationStrat::run(std::vector<std::vector<std::string>> &vision)
	noexcept
{
	(void) vision;
	std::string reply = "";
	_socket.tryToRead(reply);
	if (reply != "" && reply.substr(0, reply.find(" ")) == "message") {
		if (reply.substr(reply.find_last_of(" ") + 1, 4) == "Come") {
			reply = reply.substr(reply.find(" ") + 1);
			tryToReadDirection(reply);
			move();
		}
		else if (reply.substr(reply.find_last_of(" ") + 1, 4) == "Stop")
			_stratLevel = DEFAULT;
	}
	else if (reply != "" && reply.substr(0, 18) == "Elevation underway") {
		_elevationLevel++;
		_stratLevel = DEFAULT;
	}
	else
		_socket << "Left\n";
}

void GoToElevationStrat::tryToReadDirection(std::string &reply)
{
	reply = reply.substr(0, reply.find(","));
	_direction = std::stoi(reply);
}

void GoToElevationStrat::move()
{
	switch (_direction) {
		case 1:
			_socket << "Forward\n";
			break;
		case 2:
			_socket << "Forward\n";
			_socket << "Left\n";
			_socket << "Forward\n";
			break;
		case 3:
			_socket << "Left\n";
			_socket << "Forward\n";
			break;
		case 4:
			_socket << "Left\n";
			_socket << "Forward\n";
			_socket << "Left\n";
			_socket << "Forward\n";
			break;
		case 5:
			_socket << "Left\n";
			_socket << "Left\n";
			_socket << "Forward\n";
			break;
		case 6:
			_socket << "Right\n";
			_socket << "Forward\n";
			_socket << "Right\n";
			_socket << "Forward\n";
			break;
		case 7:
			_socket << "Right\n";
			_socket << "Forward\n";
			break;
		case 8:
			_socket << "Forward\n";
			_socket << "Right\n";
			_socket << "Forward\n";
			break;
		default:
			_socket << "Left\n";
	}
}

}