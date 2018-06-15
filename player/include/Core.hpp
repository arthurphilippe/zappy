/*
** EPITECH PROJECT, 2018
** zappy
** File description:
** Client's Core
*/

#ifndef CORE_HPP_
	#define CORE_HPP_
	#include <vector>
	#include <string>
	#include <stdexcept>
	#include <iostream>
	#include "Socket.hpp"
	#include "Processing.hpp"
	#include "AI.hpp"

namespace pl {

	class Core {
	public:
		Core(int ac, char **av);
		~Core();
		void loop();
	private:
		void parseArgs(std::vector<std::string> &args);
		void initConnection(const std::string &port,
			const std::string &machine);
		Socket		_socket;
		Processing	_processing;
		AI		_ai;
		std::string	_teamName;

	};

}

#endif /* !CORE_HPP_ */