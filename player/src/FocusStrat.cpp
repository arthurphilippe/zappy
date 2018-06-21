/*
** EPITECH PROJECT, 2018
** zappy
** File description:
** Created by victor,
*/

#include "FocusStrat.hpp"
#include "color.h"

pl::FocusStrat::FocusStrat(pl::Socket &socket)
	: AStrat(socket)
{
}

pl::FocusStrat::~FocusStrat()
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
