/*
** EPITECH PROJECT, 2018
** zappy
** File description:
** Created by victor,
*/

#ifndef ZAPPY_FOCUSITEM_HPP
	#define ZAPPY_FOCUSITEM_HPP

	#include <random>
	#include <queue>
	#include <iostream>
	#include <algorithm>
	#include "Socket.hpp"
	#include "AStrat.hpp"

namespace pl {
	class FocusStrat : public AStrat {
		public:
			FocusStrat(Socket &socket);
			~FocusStrat();
		private:
			void moveToItem(int itemPos);
			void run(std::vector<std::vector<std::string>> &vision) noexcept;
	};
}

#endif //ZAPPY_FOCUSITEM_HPP
