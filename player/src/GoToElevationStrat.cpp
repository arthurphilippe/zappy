/*
** EPITECH PROJECT, 2018
** zappy
** File description:
** AI's GoToElevation strat
*/

#include "GoToElevationStrat.hpp"

namespace pl {

GoToElevationStrat::GoToElevationStrat(Socket &socket)
	: _status(false), _socket(socket)
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
		default:
			_socket << "Forward";
	}
}

}