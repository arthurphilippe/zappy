/*
** EPITECH PROJECT, 2018
** zappy
** File description:
** Created by victor,
*/

#ifndef ZAPPY_ASTRAT_HPP
#define ZAPPY_ASTRAT_HPP

#include <deque>
#include <color.h>
#include "IStrat.hpp"

namespace pl::strat {

class AStrat : public IStrat {
public:
	AStrat(Socket &socket);
	virtual ~AStrat() = default;
	bool isRuning() noexcept override {return _status;};
protected:
	int getClosestItemPos(std::vector<std::vector<std::string>> &vision);
	void harvest(std::vector<std::string> &vision) noexcept;
	void executeAction() noexcept;
	void showVision(std::vector<std::vector<std::string>> &vision) noexcept;
	void showQueue() noexcept;
	bool			_status;
	Socket			&_socket;
	std::string		_itemName;
	std::deque<std::string>	_actionQueue;
};

}

#endif //ZAPPY_ASTRAT_HPP
