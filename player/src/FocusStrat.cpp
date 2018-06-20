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
	if ((itemPos = getClosestItemPos(vision)) > 0)
		moveToItem(itemPos);
	else
		move("Right\n");
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
	_actionQueue.pop_back();
	if (_actionQueue.empty())
		_status = false;
}

int pl::FocusStrat::getClosestItemPos(std::vector<std::vector<std::string>> &vision)
{
	int itemPos = 0;

	for (const auto &itemList : vision) {
		for (auto item = itemList.begin(); item != itemList.end(); item++, itemPos++) {
			if (!item->empty() && *item != "player") {
				_itemName = *item;
				return (itemPos);
			}
		}
	}
	return (0);
}

void pl::FocusStrat::moveToItem(int itemPos)
{
	int visionLevel = 1;
	int middle = 0, nbForward, min, max;
	bool findLine = false;

	while (findLine != true) {
		middle = visionLevel * (visionLevel + 1);
		min = middle - visionLevel;
		max = middle + visionLevel;
		if (min <= itemPos && itemPos <= max)
			findLine = true;
		else {
			visionLevel++;
			_actionQueue.push_back("Forward\n");
		}
	}
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
}