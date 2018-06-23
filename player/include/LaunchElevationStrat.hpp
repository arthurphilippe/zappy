/*
** EPITECH PROJECT, 2018
** zappy
** File description:
** AI's launch elevation strategy
*/

#ifndef LAUNCHELEVATION_HPP_
	#define LAUNCHELEVATION_HPP_
	#include "AStrat.hpp"
	#include "Socket.hpp"
	#include <vector>
	#include <array>
	#include <queue>

namespace pl {

	class LaunchElevationStrat : public AStrat {
	public:
		LaunchElevationStrat(Socket &socket, STRAT &stratLevel,
			int &elevationLevel,
			std::vector<std::array<int, 6>> &elevation);
		~LaunchElevationStrat();
		void run(std::vector<std::vector<std::string>> &vision)
			noexcept override;
	private:
		void checkForPlayers(std::vector<std::vector<std::string>>
			&vison) noexcept;
		int nbOfPlayersNeeded();
		void runIncantation();
		std::string getStoneName(int i) const;

		STRAT					&_stratLevel;
		int					&_elevationLevel;
		bool					_isElevated;
		std::vector<std::array<int, 6>>		_elevation;
	};

}

#endif /* !LAUNCHELEVATION_HPP_ */
