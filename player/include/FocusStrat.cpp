/*
** EPITECH PROJECT, 2018
** zappy
** File description:
** Created by victor,
*/

#include "FocusStrat.hpp"

pl::FocusStrat::FocusStrat(pl::Socket &socket) :
_status(false), _socket(socket), _actionQueue()
{
}

void pl::FocusStrat::run(std::vector<std::vector<std::string>> &vision) noexcept
{
	int itemPos = 0;

	if (!_actionQueue.empty()) {
		executeAction();
		return;
	}
	if ((itemPos = getClosestItem(vision)) > 0)
		takeDecisions(itemPos, vision.size());
	else
		move("Right\n");
}

void pl::FocusStrat::move(std::string direction) noexcept
{
	_socket << direction;
	_actionQueue.push("Forward\n");
	_status = true;
}

void pl::FocusStrat::executeAction() noexcept
{
	std::string action = _actionQueue.front();

	_socket << action;
	_actionQueue.pop();
	if (_actionQueue.empty())
		_status = false;
}

void pl::FocusStrat::takeDecisions(int itemPos, unsigned long visionSize)
{
	switch (visionSize) {
	case 4:
		moveToItem(1, itemPos, 2);
	case 9:
		moveToItem(2, itemPos, 6);
	case 16:
		moveToItem(3, itemPos, 12);
	default:
		break;
	}
}

int pl::FocusStrat::getClosestItem(std::vector<std::vector<std::string>> &vision)
{
	int itemPos = 0;

	for (const auto &itemList : vision) {
		for (auto item = itemList.begin(); item != itemList.end(); item++, itemPos++) {
			if (!item->empty() && *item != "player")
				return (itemPos);
		}
	}
	return (0);
}

void pl::FocusStrat::moveToItem(int nbForward, int itemPos, int myPos)
{
	while (nbForward-- > 0)
		_actionQueue.push("Forward\n");
	while (itemPos != myPos) {
		if (itemPos < myPos) {
			_actionQueue.push("Left\n");
			myPos--;
		} else if (itemPos > myPos) {
			_actionQueue.push("Right\n");
			myPos++;
		}
	}
}

/*bool pl::FocusStrat::itemInVision(std::vector<std::vector<std::string>> &vision)
{
	if (std::find(vision.begin(), vision.end(), "linemate") != vision.end() ||
		std::find(vision.begin(), vision.end(), "sibur") != vision.end() ||
		std::find(vision.begin(), vision.end(), "phiras") != vision.end() ||
		std::find(vision.begin(), vision.end(), "thystame") != vision.end() ||
		std::find(vision.begin(), vision.end(), "mendiane") != vision.end() ||
		std::find(vision.begin(), vision.end(), "deraumere") != vision.end() ||
		std::find(vision.begin(), vision.end(), "food") != vision.end())
			return (true);
	return (false);
}*/
