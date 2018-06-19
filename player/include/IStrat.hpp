/*
** EPITECH PROJECT, 2018
** zappy
** File description:
** IStrat
*/

#ifndef ISTRAT_HPP_
	#define ISTRAT_HPP_

	#include <string>
	#include <vector>
	#include "Socket.hpp"

namespace pl {
class IStrat {
	public:
		IStrat() = default;
		virtual ~IStrat() = default;
		virtual void run(std::vector<std::vector<std::string>> &vision) = 0;
		virtual bool isRuning() = 0;
};
}

#endif /* !ISTRAT_HPP_ */
