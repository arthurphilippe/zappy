/*
** EPITECH PROJECT, 2018
** zappy
** File description:
** DefaultStrat
*/

#ifndef DEFAULTSTRAT_HPP_
	#define DEFAULTSTRAT_HPP_

	#include <random>
	#include <queue>
	#include <iostream>
	#include "Socket.hpp"
	#include "IStrat.hpp"
	#include "AStrat.hpp"

namespace pl {
class DefaultStrat : public AStrat {
	public:
		DefaultStrat(Socket &socket);
		~DefaultStrat();
		void run(std::vector<std::vector<std::string>> &vision) noexcept override;
	private:
		std::mt19937		_generator;
		std::uniform_int_distribution<std::mt19937::result_type> _limits;
};
}

#endif /* !DEFAULTSTRAT_HPP_ */
