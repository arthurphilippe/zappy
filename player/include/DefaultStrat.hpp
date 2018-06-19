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

namespace pl {
class DefaultStrat : public IStrat {
	public:
		DefaultStrat(Socket &socket);
		~DefaultStrat();
		void run(std::vector<std::string> &vision) noexcept override;
		bool isRuning() noexcept override {return _status;};
	private:
		bool			_status;
		Socket			&_socket;
		std::queue<std::string>	_actionQueue;
		std::mt19937		_generator;
		std::uniform_int_distribution<std::mt19937::result_type> _limits;

		void executeAction() noexcept;
		void move(std::string direction) noexcept;
};
}

#endif /* !DEFAULTSTRAT_HPP_ */
