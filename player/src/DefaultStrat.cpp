/*
** EPITECH PROJECT, 2018
** zappy
** File description:
** DefaultStrat
*/

#include "DefaultStrat.hpp"
#include "color.h"

pl::DefaultStrat::DefaultStrat(Socket &socket)
	: _status(false), _socket(socket), _actionQueue(), _generator(), _limits(0, 2)
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
		executeAction(vision);
		return;
	}
	int action = static_cast<int>(_limits(_generator));
	switch (action) {
		case 1:
			move("Left\n");
			break;
		case 2:
			move("Right\n");
			break;
		default:
			_socket << "Forward\n";
			_actionQueue.push("Harvest");
	}
};

void pl::DefaultStrat::move(std::string direction) noexcept
{
	_socket << direction;
	_actionQueue.push("Forward\n");
	_actionQueue.push("Harvest");
	_status = true;
}

void pl::DefaultStrat::harvest(std::vector<std::vector<std::string>> &vision) noexcept
{
	for (auto it = vision[0].begin(); it != vision[0].end(); it++) {
		if (*it != "player") {
			std::string action = "Take " + *it + "\n";
			_actionQueue.push(action);
			_status = true;
		}
	}
}

void pl::DefaultStrat::executeAction(std::vector<std::vector<std::string>> &vision) noexcept
{
	std::string action = _actionQueue.front();
	if (action != "Harvest") {
		_socket << action;
		_actionQueue.pop();
	} else {
		_actionQueue.pop();
		harvest(vision);
		std::string somthingToHarvest = _actionQueue.front();
		if (somthingToHarvest.size() > 0) {
			_socket << somthingToHarvest;
			_actionQueue.pop();
		} else
			_socket << "Forward\n";
	}
	showQueue();
	if (_actionQueue.empty())
		_status = false;
}

void pl::DefaultStrat::showVision(std::vector<std::vector<std::string>> &vision) noexcept
{
	int b = 0;
	for (auto it: vision) {
		std::cout << "Case [" << ANSI_BOLD_COLOR_CYAN << b << ANSI_BOLD_COLOR_RESET << "] : [";
		for (auto i: it){
			std::cout << ANSI_BOLD_COLOR_YELLOW << i << ANSI_BOLD_COLOR_RESET << ", ";
		}
		std::cout << "]\n";
		b++;
	}
}

void pl::DefaultStrat::showQueue() noexcept
{
	std::queue<std::string> cpyQueue = _actionQueue;
	std::cout << "\nIn Queue: [";
	while (!cpyQueue.empty()) {
		std::cout << ANSI_BOLD_COLOR_YELLOW<< cpyQueue.front() << ANSI_BOLD_COLOR_RESET<< ",";
		cpyQueue.pop();
	}
	std::cout << "]" << std::endl;
}
