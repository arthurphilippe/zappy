/*
** EPITECH PROJECT, 2018
** zappy
** File description:
** Created by victor,
*/

#include "AStrat.hpp"

namespace pl::strat {

AStrat::AStrat(Socket &socket) :
_status(false), _socket(socket), _actionQueue()
{
}

void AStrat::harvest(std::vector<std::string> &vision) noexcept
{
	for (auto it = vision.begin(); it != vision.end(); it++) {
		if (*it != "player") {
			std::string action = "Take " + *it + "\n";
			_actionQueue.push_front(action);
			_status = true;
		}
	}
}

void AStrat::showVision(std::vector<std::vector<std::string>> &vision) noexcept
{
	int b = 0;
	for (auto it: vision) {
		std::cout << "Case [" << ANSI_BOLD_COLOR_CYAN << b << ANSI_BOLD_COLOR_RESET << "] : [";
		for (auto i: it){
			std::cout << ANSI_BOLD_COLOR_YELLOW << i << ANSI_BOLD_COLOR_RESET << ", ";
		}
		std::cout << "]\n";
		b++;
	}
}

void AStrat::showQueue() noexcept
{
	std::deque<std::string> cpyQueue = _actionQueue;
	std::cout << "\nIn Queue: [";
	while (!cpyQueue.empty()) {
		std::cout << ANSI_BOLD_COLOR_YELLOW<< cpyQueue.front() << ANSI_BOLD_COLOR_RESET << ",";
		cpyQueue.pop_front();
	}
	std::cout << "]" << std::endl;
}

int AStrat::getClosestItemPos(std::vector<std::vector<std::string>> &vision)
{
	int itemPos = 0;

	for (const auto &itemList : vision) {
		for (auto item = itemList.begin(); item != itemList.end(); item++) {
			if (!item->empty() && *item != "player") {
				_itemName = *item;
				std::cout << ANSI_BOLD_COLOR_BLUE << "Item Found : " << _itemName << " at pos : ";
				std::cout << itemPos << ANSI_BOLD_COLOR_RESET << std::endl;
				return (itemPos);
			}
		}
		itemPos++;
	}
	return (-1);
}

void AStrat::executeAction() noexcept
{
	std::string action = _actionQueue.front();

	_socket << action;
	_actionQueue.pop_front();
	showQueue();
	if (_actionQueue.empty())
		_status = false;
}

}
