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

namespace pl::strat {

class Focus : public AStrat {
	public:
		Focus(Socket &socket);
		~Focus();
	private:
		void moveToItem(int itemPos);
		void run(std::vector<std::vector<std::string>> &vision) noexcept;
};

}

#endif //ZAPPY_FOCUSITEM_HPP
