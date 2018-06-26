/*
** EPITECH PROJECT, 2018
** zappy
** File description:
** Default
*/

#include "Default.hpp"
#include "color.h"

namespace pl::strat {

Default::Default(Socket &socket)
	: AStrat(socket), _generator(), _limits(0, 2)
{
	_generator.seed(std::random_device()());
}

Default::~Default()
{
}

void Default::run(std::vector<std::vector<std::string>> &vision)
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
			_status = true;
			break;
		case 2:
			harvest(vision[0]);
			_actionQueue.push_back("Right\n");
			_actionQueue.push_back("Forward\n");
			_status = true;
			break;
		default:
			harvest(vision[0]);
			_actionQueue.push_back("Forward\n");
			_status = true;
	}
	executeAction();
};

}
