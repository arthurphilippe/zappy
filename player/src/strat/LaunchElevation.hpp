/*
** EPITECH PROJECT, 2018
** zappy
** File description:
** AI's launch elevation strategy
*/

#ifndef LAUNCHELEVATION_HPP_
	#define LAUNCHELEVATION_HPP_

	#include <array>
	#include <queue>
	#include <vector>
	#include "IStrat.hpp"
	#include "Socket.hpp"

namespace pl::strat {

class LaunchElevation : public IStrat {
public:
	LaunchElevation(Socket &socket, STRAT &stratLevel,
		int &elevationLevel,
		std::vector<std::array<int, 6>> &elevation);
	~LaunchElevation();
	void run(std::vector<std::vector<std::string>> &vision)
		noexcept override;
	bool isRuning() noexcept override {return _status;};
private:
	void checkForPlayers(std::vector<std::vector<std::string>>
		&vison) noexcept;
	int nbOfPlayersNeeded();
	void runIncantation();
	std::string getStoneName(int i) const;

	bool					_status;
	STRAT					&_stratLevel;
	int					&_elevationLevel;
	Socket					&_socket;
	bool					_isElevated;
	std::vector<std::array<int, 6>>		_elevation;
};

}

#endif /* !LAUNCHELEVATION_HPP_ */
