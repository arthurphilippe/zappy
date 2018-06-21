/*
** EPITECH PROJECT, 2018
** zappy
** File description:
** Created by victor,
*/

#include "FocusStrat.hpp"
#include "color.h"

pl::FocusStrat::FocusStrat(pl::Socket &socket) :
_status(false), _socket(socket), _actionQueue()
{
}

void pl::FocusStrat::run(std::vector<std::vector<std::string>> &vision) noexcept
{
	int itemPos = 0;

	showVision(vision);
	if (!_actionQueue.empty()) {
		executeAction();
		showQueue();
		return;
	}
	if ((itemPos = getClosestItemPos(vision)) == 0)
		_socket << "Take " + _itemName + "\n";
	else if ((itemPos = getClosestItemPos(vision)) > 0)
		moveToItem(itemPos);
	else {
		_socket << "Right\n";
		_actionQueue.push_front("Forward\n");
	}
	showQueue();
}

void pl::FocusStrat::move(std::string direction) noexcept
{
	_socket << direction;
	_actionQueue.push_back("Forward\n");
	_status = true;
}

void pl::FocusStrat::executeAction() noexcept
{
	std::string action = _actionQueue.front();

	_socket << action;
	_actionQueue.pop_front();
	if (_actionQueue.empty())
		_status = false;
}

int pl::FocusStrat::getClosestItemPos(std::vector<std::vector<std::string>> &vision)
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

void pl::FocusStrat::moveToItem(int itemPos)
{
	int visionLevel = 1;
	int middle = 0, nbForward, min, max;
	bool findLine = false;

	_actionQueue.push_back("Forward\n");
	while (findLine != true) {
		middle = visionLevel * (visionLevel + 1);
		min = middle - visionLevel;
		max = middle + visionLevel;
		std::cout << ANSI_BOLD_COLOR_RED << "Min: " << min << ANSI_BOLD_COLOR_RESET << std::endl;
		std::cout << ANSI_BOLD_COLOR_RED << "Middle: " << middle << ANSI_BOLD_COLOR_RESET << std::endl;
		std::cout << ANSI_BOLD_COLOR_RED << "MAX: " << max << ANSI_BOLD_COLOR_RESET << std::endl;
		if (min <= itemPos && itemPos <= max) {
			std::cout << ANSI_BOLD_COLOR_RED << "FOUND LINE" << ANSI_BOLD_COLOR_RESET << std::endl;
			findLine = true;
		}
		else {
			visionLevel++;
			_actionQueue.push_back("Forward\n");
		}
	}
	std::cout << ANSI_BOLD_COLOR_RED << "LEAVING LOOP" << ANSI_BOLD_COLOR_RESET << std::endl;
	if (itemPos < middle)
		_actionQueue.push_back("Left\n");
	else if (itemPos > middle)
		_actionQueue.push_back("Right\n");
	nbForward = itemPos - middle;
	if (nbForward < 0)
		nbForward *= -1;
	while (nbForward > 0) {
		_actionQueue.push_back("Forward\n");
		nbForward--;
	}
	_actionQueue.push_back("Take " + _itemName + "\n");
	executeAction();
}

void pl::FocusStrat::showVision(std::vector<std::vector<std::string>> &vision) noexcept
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

void pl::FocusStrat::showQueue() noexcept
{
	std::deque<std::string> cpyQueue = _actionQueue;
	std::cout << "\nIn Queue: [";
	while (!cpyQueue.empty()) {
		std::cout << ANSI_BOLD_COLOR_YELLOW<< cpyQueue.front() << ANSI_BOLD_COLOR_RESET<< ",";
		cpyQueue.pop_front();
	}
	std::cout << "]" << std::endl;
}
