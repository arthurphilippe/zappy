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

namespace pl {
class IStrat {
	public:
		IStrat() = default;
		~IStrat() = default;
		virtual void run(std::vector<std::string> &vision) = 0;
};
}

#endif /* !ISTRAT_HPP_ */
