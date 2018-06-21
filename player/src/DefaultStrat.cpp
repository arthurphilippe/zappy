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

void pl::DefaultStrat::harvest(std::vector<std::string> &vision) noexcept
{
	for (auto it = vision.begin(); it != vision.end(); it++) {
		if (*it != "player") {
			std::string action = "Take " + *it + "\n";
			_actionQueue.push_front(action);
			_status = true;
		}
	}
}

void pl::DefaultStrat::executeAction() noexcept
{
	std::string action = _actionQueue.front();
	_socket << action;
	_actionQueue.pop_front();
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
	std::deque<std::string> cpyQueue = _actionQueue;
	std::cout << ANSI_BOLD_COLOR_GREEN << "\nIn Queue:" << ANSI_BOLD_COLOR_RESET << "[" ;
	while (!cpyQueue.empty()) {
		std::cout << ANSI_BOLD_COLOR_YELLOW<< cpyQueue.front() << ANSI_BOLD_COLOR_RESET<< ",";
		cpyQueue.pop_front();
	}
	std::cout << "]" << std::endl;
}
