/*
** EPITECH PROJECT, 2018
** zappy
** File description:
** DefaultStrat
*/

#include "DefaultStrat.hpp"

pl::DefaultStrat::DefaultStrat(Socket &socket)
	: _socket(socket), _actionQueue(), _generator()
{
	_generator.seed(std::random_device()());
	_limits(0, 2);
}

pl::DefaultStrat::~DefaultStrat()
{
}

void pl::DefaultStrat::run(std::vector<std::string> &vision)
{
	(void) vision;
	if (!_actionQueue.empty())
	int action = static_cast<int>(_limits(_generator));
};
