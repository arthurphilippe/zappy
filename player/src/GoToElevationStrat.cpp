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
	: AStrat(socket), _direction(1),
		_stratLevel(stratLevel), _elevationLevel(elevationLevel)
{}

GoToElevationStrat::~GoToElevationStrat()
{}

void GoToElevationStrat::run(std::vector<std::vector<std::string>> &vision)
	noexcept
{
	(void) vision;
	if (!_actionQueue.empty()) {
		executeAction();
		return;
	}
	std::string reply = "";
	_socket.tryToRead(reply);
	if (reply != "" && reply.substr(0, reply.find(" ")) == "message") {
		if (reply.substr(reply.find_last_of(" ") + 1, 4) == "Come") {
			reply = reply.substr(reply.find(" ") + 1);
			tryToReadDirection(reply);
			moveToQueue();
			executeAction();
		}
		else if (reply.substr(reply.find_last_of(" ") + 1, 4) == "Stop")
			_stratLevel = DEFAULT;
	}
	else if (reply != "" && reply.substr(0, 18) == "Elevation underway") {
		_elevationLevel++;
		_stratLevel = DEFAULT;
		exit(55);
	}
	else {
		_actionQueue.push_back("Left\n");
		executeAction();
	}
}

void GoToElevationStrat::tryToReadDirection(std::string &reply)
{
	reply = reply.substr(0, reply.find(","));
	_direction = std::stoi(reply);
}

void GoToElevationStrat::moveToQueue()
{
	switch (_direction) {
		case 1:
			_actionQueue.push_back("Forward\n");
			break;
		case 2:
			_actionQueue.push_back("Forward\n");
			_actionQueue.push_back("Left\n");
			_actionQueue.push_back("Forward\n");
			break;
		case 3:
			_actionQueue.push_back("Left\n");
			_actionQueue.push_back("Forward\n");
			break;
		case 4:
			_actionQueue.push_back("Left\n");
			_actionQueue.push_back("Forward\n");
			_actionQueue.push_back("Left\n");
			_actionQueue.push_back("Forward\n");
			break;
		case 5:
			_actionQueue.push_back("Left\n");
			_actionQueue.push_back("Left\n");
			_actionQueue.push_back("Forward\n");
			break;
		case 6:
			_actionQueue.push_back("Right\n");
			_actionQueue.push_back("Forward\n");
			_actionQueue.push_back("Right\n");
			_actionQueue.push_back("Forward\n");
			break;
		case 7:
			_actionQueue.push_back("Right\n");
			_actionQueue.push_back("Forward\n");
			break;
		case 8:
			_actionQueue.push_back("Forward\n");
			_actionQueue.push_back("Right\n");
			_actionQueue.push_back("Forward\n");
			break;
		default:
			_actionQueue.push_back("Left\n");
	}
}

}
