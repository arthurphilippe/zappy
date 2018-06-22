/*
** EPITECH PROJECT, 2018
** zappy
** File description:
** Client's AI
*/

#ifndef AI_HPP_
	#define AI_HPP_
	#include <iostream>
	#include <vector>
	#include <unordered_map>
	#include <memory>
	#include "Socket.hpp"
	#include "Processing.hpp"
	#include "IStrat.hpp"
	#include "DefaultStrat.hpp"
	#include "FocusStrat.hpp"
	#include "GoToElevationStrat.hpp"

namespace pl {

	class AI {
	public:
		enum STRAT {
			DEFAULT,
			GO_TO_ELEVATION
		};
		AI();
		~AI();
		void initStrats(Socket &socket);
		void look(Socket &socket,
			const Processing &processing);
		void lookAtInventory(Socket &socket,
			const Processing &processing);
		void executeStrat(Socket &_socket,
			const Processing &processing) noexcept;
		void setMapX(int X)
		{
			_mapX = X;
		}
		void setMapY(int Y)
		{
			_mapX = Y;
		}
		bool getStratStatus() {return _status;};
	private:
		void clearVision();
		void clearInventory();
		int					_mapX;
		int					_mapY;
		bool					_status;
		STRAT					_stratLevel;
		std::vector<std::vector<std::string>>	_vision;
		std::unordered_map<std::string, int>	_inventory;
		std::vector<std::unique_ptr<IStrat>>	_strats;
	};

}

#endif /* !AI_HPP_ */
