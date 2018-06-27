/*
** EPITECH PROJECT, 2018
** player
** File description:
** Player
*/

#include <iostream>
#include "Player.hpp"
#include "ParsingTools.hpp"
#include "Processing.hpp"

namespace pl {

std::unordered_map<Action, std::string> Player::__actionNames {
	{Action::FORWARD, "Forward"},
	{Action::RIGHT, "Right"},
	{Action::LEFT, "Left"},
	{Action::LOOK, "Look"},
	{Action::INVENTORY, "Inventory"},
	{Action::CONNECT_NBR, "Connect_nbr"},
	{Action::FORK, "Fork"},
	{Action::EJECT, "Eject"},
	{Action::INCANTATION, "Incantation"},
	{Action::BROADCAST, "Broadcast"},
	{Action::SET, "Set"},
	{Action::TAKE, "Take"},
};

std::unordered_map<Stone, std::string> Player::__stoneNames {
	{Stone::LINEMATE, "linemate"},
	{Stone::DERAUMERE, "deraumere"},
	{Stone::SIBUR, "sibur"},
	{Stone::MENDIANE, "mendiane"},
	{Stone::PHIRAS, "phiras"},
	{Stone::THYSTAME, "thystame"},
};

Player::Player(ILink &link)
	: _link(link), _hasVisionChanged(false),
	_hasInventoryChanged(false), _level(1)
{
	_replyMap[Action::FORWARD] = [&]() { this->_uponReplyPop (); };
	_replyMap[Action::RIGHT] = [&]() { this->_uponReplyPop (); };
	_replyMap[Action::LEFT] = [&]() { this->_uponReplyPop (); };
	_replyMap[Action::LOOK] = [&]() { this->_uponReplyLook(); };
	_replyMap[Action::INVENTORY] =
		[&]() { this->_uponReplyInventory(); };
	_replyMap[Action::CONNECT_NBR] =
		[&]() { this->_uponReplyConnectnbr(); };
	_replyMap[Action::FORK] = [&]() { this->_uponReplyPop (); };
	_replyMap[Action::EJECT] = [&]() { this->_uponReplyPop (); };
	_replyMap[Action::INCANTATION] =
		[&]() { this->_uponReplyIncant(); };
	_replyMap[Action::BROADCAST] = [&]() { this->_uponReplyPop (); };
	_replyMap[Action::SET] = [&]() { this->_uponReplyPop (); };
	_replyMap[Action::TAKE] = [&]() { this->_uponReplyPop (); };

}

Player::~Player()
{}

/*
** Adds an action to be performed to the queue.
*/
void Player::doAction(Action act, bool prioritise)
{
	if (prioritise) {
		_actionQueue.push_front(act);
		if (act > Action::NO_PARAM_SPACER)
			_paramQueue.push_front("");
	} else {
		_actionQueue.push_back(act);
		if (act > Action::NO_PARAM_SPACER)
			_paramQueue.push_back("");
	}
}

/*
** Adds an action to be performed to the queue taking a stone parameter
*/
void Player::doAction(Action act, Stone res, bool prioritise)
{
	if (prioritise) {
		_actionQueue.push_front(act);
		_paramQueue.push_front(__stoneNames[res]);
	} else {
		_actionQueue.push_back(act);
		_paramQueue.push_back(__stoneNames[res]);
	}
}

/*
** Adds an action to be performed to the queue taking a string parameter
*/
void Player::doAction(Action act, const std::string &str, bool prioritise)
{
	if (prioritise) {
		_actionQueue.push_front(act);
		_paramQueue.push_front(str);
	} else {
		_actionQueue.push_back(act);
		_paramQueue.push_back(str);
	}
}

/*
** While the server can still accept commands, offloads commands from
** the actionqueue onto the socket.
*/
void Player::offloadActions()
{
	this->_pollReplies();
	while (_sentActions.size() < COMMAND_LIMIT && _actionQueue.size()) {
		const auto &act = _actionQueue.front();
		std::string tmp{__actionNames[act]};
		if (act > Action::NO_PARAM_SPACER && _paramQueue.size()) {
			tmp.append(" ");
			tmp.append(_paramQueue.front());
			_paramQueue.pop_front();
		}
		tmp.append("\n");
		_link << tmp;
		_sentActions.push(act);
		_actionQueue.pop_front();
	}
}

/*
** Polls the socket for replies, splits them and adds them to the
** reply queue.
*/
void Player::_pollReplies()
{
	std::string buff;
	std::string tmp;

	while (_link.read(tmp)) {
		buff += tmp;
	}
	auto splitBuf = ParsingTools::createVectorString(buff, '\n');
	for (auto &it : splitBuf) {
		_replies.push(it);
	}
	this->_processReplies();
}

void Player::_uponReplyPop()
{
	_sentActions.pop();
}

void Player::_uponReplyLook()
{
	_sentActions.pop();
	Processing::vision(_replies.front(), _vision);
	_hasVisionChanged = true;
}

void Player::_uponReplyInventory()
{
	_sentActions.pop();
	Processing::inventory(_replies.front(), _inventory);
	_hasInventoryChanged = true;
}

void Player::_uponReplyConnectnbr()
{
	_sentActions.pop();
}

void Player::_uponReplyIncant()
{
	_sentActions.pop();
	_level += 1;
}

void Player::_processReplies()
{
	while (_replies.size()) {
		auto reply = _replies.front();
		auto firstWord = ParsingTools::extractFirstString(reply, ' ');
		const auto &it = _replyMap.find(_sentActions.front());
		if (firstWord == "Message") {
			_msgq.push(reply);
		} else if (firstWord == "Elevation"
			&& _sentActions.front() != Action::INCANTATION) {
			_level += 1;
		} else if (it != _replyMap.end()) {
			it->second();
		}
		_replies.pop();
	}
}

}
