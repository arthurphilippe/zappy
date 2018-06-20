/*
** EPITECH PROJECT, 2018
** zappy
** File description:
** AI's GoToElevation strat
*/

#include "GoToElevationStrat.hpp"

namespace pl {

GoToElevationStrat::GoToElevationStrat(Socket &socket)
	: _status(false), _socket(socket), _direction(1)
{}

GoToElevationStrat::~GoToElevationStrat()
{}

void GoToElevationStrat::run(std::vector<std::vector<std::string>> &vision)
	noexcept
{
	(void) vision;
	std::string reply;
	if (_socket.tryToRead(reply) &&
		reply.substr(0, reply.find(" ")) == "message") {
		reply = reply.substr(reply.find(" ") + 1);
		tryToReadDirection(reply);
	}
	move();
}

void GoToElevationStrat::tryToReadDirection(std::string &reply)
{
	reply = reply.substr(0, reply.find(","));
	_direction = std::stoi(reply);
}

void GoToElevationStrat::move()
{
	switch (_direction) {
		case 2:
			_socket << "Forward\n";
			_socket << "Left\n";
			_socket << "Forward\n";
			break;
		case 4:
			_socket << "Left\n";
			_socket << "Forward\n";
		case 3:
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
			_socket << "Forward\n";
	}
}

}