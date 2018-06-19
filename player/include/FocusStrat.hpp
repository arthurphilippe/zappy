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
	#include "IStrat.hpp"

namespace pl {
	class FocusStrat : public IStrat {
		public:
			FocusStrat(Socket &socket);
			~FocusStrat() {};
			void run(std::vector<std::vector<std::string>> &vision) noexcept override;
			bool isRuning() noexcept override {return _status;};
		private:
			void executeAction() noexcept;
			void takeDecisions(int itemPos, unsigned long visionSize);
			void moveToItem(int nbForward, int itemPos, int myPos);
			int getClosestItem(std::vector<std::vector<std::string>> &vision);
			void move(std::string direction) noexcept;
			bool			_status;
			Socket			&_socket;
			std::queue<std::string>	_actionQueue;
			//bool itemInVision(std::vector<std::vector<std::string>> &vision);
	};
}

#endif //ZAPPY_FOCUSITEM_HPP
