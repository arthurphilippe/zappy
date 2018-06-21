/*
** EPITECH PROJECT, 2018
** zappy
** File description:
** AI's launch elevation strategy
*/

#ifndef LAUNCHELEVATION_HPP_
	#define LAUNCHELEVATION_HPP_
	#include "IStrat.hpp"
	#include "Socket.hpp"
	#include <vector>
	#include <queue>

namespace pl {

	class LaunchElevationStrat : public IStrat {
	public:
		LaunchElevationStrat(Socket &socket, int &elevationLevel);
		~LaunchElevationStrat();
		void run(std::vector<std::vector<std::string>> &vision)
			noexcept override;
		bool isRuning() noexcept override {return _status;};
	private:
		void checkForPlayers(std::vector<std::vector<std::string>>
			&vison) noexcept;
		bool			_status;
		int			&_elevationLevel;
		Socket			&_socket;
		bool			_isElevated;
	};

}

#endif /* !LAUNCHELEVATION_HPP_ */