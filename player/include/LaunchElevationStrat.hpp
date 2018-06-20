/*
** EPITECH PROJECT, 2018
** zappy
** File description:
** AI's launch elevation strategy
*/

#ifndef LAUNCHELEVATION_HPP_
	#define LAUNCHELEVATION_HPP_
	#include "IStrat.hpp"
	#include <vector>
	#include <queue>

namespace pl {

	class LaunchElevationStrat : public IStrat {
	public:
		LaunchElevationStrat(Socket &socket);
		~LaunchElevationStrat();
		void run(std::vector<std::vector<std::string>> &vision)
			noexcept override;
		bool isRuning() noexcept override {return _status;};
	private:
		bool			_status;
		Socket			&_socket;
		std::queue<std::string>	_generator;
	};

}

#endif /* !LAUNCHELEVATION_HPP_ */