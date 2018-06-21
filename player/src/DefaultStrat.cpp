/*
** EPITECH PROJECT, 2018
** zappy
** File description:
** DefaultStrat
*/

#include "DefaultStrat.hpp"
#include "color.h"

pl::DefaultStrat::DefaultStrat(Socket &socket)
	: AStrat(socket), _generator(), _limits(0, 2)
{
	_generator.seed(std::random_device()());
}

pl::DefaultStrat::~DefaultStrat()
{
}

void pl::DefaultStrat::run(std::vector<std::vector<std::string>> &vision)
	noexcept
{
	showVision(vision);
	if (!_actionQueue.empty()) {
		executeAction();
		return;
	}
	int action = static_cast<int>(_limits(_generator));
	switch (action) {
		case 1:
			harvest(vision[0]);
			_actionQueue.push_back("Left\n");
			_actionQueue.push_back("Forward\n");
			break;
		case 2:
			harvest(vision[0]);
			_actionQueue.push_back("Right\n");
			_actionQueue.push_back("Forward\n");
			break;
		default:
			harvest(vision[0]);
			_actionQueue.push_back("Forward\n");
	}
	executeAction();
};
