/*
** EPITECH PROJECT, 2018
** zappy
** File description:
** ElevationAI
*/

#ifndef ELEVATIONAI_HPP_
	#define ELEVATIONAI_HPP_

	#include <queue>
	#include <iostream>
	#include "Socket.hpp"
	#include "IStrat.hpp"

namespace pl {
class ElevationAI : public IStrat {
	public:
		ElevationAI(Socket &socket);
		~ElevationAI();
		void run(std::vector<std::vector<std::string>> &vision) noexcept override;
		bool isRuning() noexcept override {return _status;};

	private:
		bool	_status;
		Socket	&_socket;
};
}

#endif /* !ELEVATIONAI_HPP_ */
