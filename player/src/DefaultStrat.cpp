/*
** EPITECH PROJECT, 2018
** zappy
** File description:
** DefaultStrat
*/

#include "DefaultStrat.hpp"

pl::DefaultStrat::DefaultStrat(Socket &socket)
	: _status(false), _socket(socket), _actionQueue(), _generator(), _limits(0, 3)
{
	_generator.seed(std::random_device()());
}

pl::DefaultStrat::~DefaultStrat()
{
}

void pl::DefaultStrat::run(std::vector<std::string> &vision) noexcept
{
	(void) vision;
	if (!_actionQueue.empty()) {
		executeAction();
		return;
	}
	int action = static_cast<int>(_limits(_generator));
	switch (action) {
		case 1:
			move("Left");
			break;
		case 2:
			move("Right");
			break;
		default:
			_socket << "Forward";
	}
};

void pl::DefaultStrat::move(std::string direction) noexcept
{
	_socket << direction;
	_actionQueue.push("Forward");
	_status = true;
}

void pl::DefaultStrat::executeAction() noexcept
{
	std::string action = _actionQueue.front();
	_socket << action;
	_actionQueue.pop();
	if (_actionQueue.empty())
		_status = false;
}
