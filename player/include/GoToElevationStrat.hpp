/*
** EPITECH PROJECT, 2018
** zappy
** File description:
** AI's GoToElevation strat
*/

#ifndef GOTOELEVATIONSTRAT_HPP_
	#define GOTOELEVATIONSTRAT_HPP_
	#include "IStrat.hpp"
	#include "Socket.hpp"

namespace pl {

	class GoToElevationStrat : public IStrat {
	public:
		GoToElevationStrat(Socket &socket, STRAT &stratLevel,
			int &elevationLevel);
		~GoToElevationStrat();
		void run(std::vector<std::vector<std::string>> &vision)
			noexcept override;
		bool isRuning() noexcept override {return _status;};
		void tryToReadDirection(std::string &reply);
	private:
		void			move();
		bool			_status;
		Socket			&_socket;
		int			_direction;
		STRAT			&_stratLevel;
		int			&_elevationLevel;
	};

}

#endif /* !GOTOELEVATIONSTRAT_HPP_ */