/*
** EPITECH PROJECT, 2018
** zappy
** File description:
** Client's Core
*/

#include "Core.hpp"
#include "color.h"

namespace pl {

Core::Core(int ac, char **av)
	: _teamName("")
{
	std::vector<std::string> args;
	for (int i = 1; i < ac; i++) {
		std::string arg = av[i];
		args.push_back(arg);
	}
	if (args.size() != 4 && args.size() != 6)
		throw std::invalid_argument("Wrong arguments number");
	parseArgs(args);
	_ai.initStrats(_socket);
}

Core::~Core()
{}

void Core::parseArgs(std::vector<std::string> &args)
{
	std::string port = "";
	std::string name = "";
	std::string machine = "localhost";
	for (auto it = args.begin(); it != args.end(); it++) {
		if (*it == "-p")
			port = *(std::next(it));
		else if (*it == "-n")
			name = *(std::next(it));
		else if (*it == "-h")
			machine = *(std::next(it));
	}
	if (port.empty() || name.empty() || machine.empty() ||
		(args.size() == 6 && args[4] != "-h"))
		throw std::invalid_argument("Wrong arguments");
	_teamName = name;
	initConnection(port, machine);
}

void Core::initConnection(const std::string &port, const std::string &machine)
{
	int X, Y;
	std::string reply;

	_socket.setPort(std::stoi(port));
	_socket.setMachine(machine);
	_socket.connectSocket();
	while (!_socket.tryToRead(reply));
	if (!_processing.checkWelcome(reply))
		throw std::runtime_error("Wrong server connection");
	_socket << _teamName;
	while (!_socket.tryToRead(reply));
	_processing.coordinates(reply, X, Y);
	_ai.setMapX(X);
	_ai.setMapX(Y);
}

void Core::loop()
{
	while (true) {
		std::cout << "_____"<< ANSI_BOLD_COLOR_CYAN << "START CYCLE" << ANSI_BOLD_COLOR_RESET << "_____" << std::endl;
		_ai.look(_socket, _processing);
		_ai.lookAtInventory(_socket, _processing);
		_ai.executeStrat(_socket, _processing);
	}
}

}
