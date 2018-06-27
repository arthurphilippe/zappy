/*
** EPITECH PROJECT, 2018
** player
** File description:
** Player
*/

#ifndef PLAYER_HPP_
	#define PLAYER_HPP_

	#include <deque>
	#include <queue>
	#include <unordered_map>
	#include <functional>
	#include "ILink.hpp"

namespace pl {

constexpr auto COMMAND_LIMIT(10);

enum class Action {
	FORWARD,
	RIGHT,
	LEFT,
	LOOK,
	INVENTORY,
	CONNECT_NBR,
	FORK,
	EJECT,
	INCANTATION,
	NO_PARAM_SPACER,
	BROADCAST,
	SET,
	TAKE,
};

enum class Stone {
	LINEMATE,
	DERAUMERE,
	SIBUR,
	MENDIANE,
	PHIRAS,
	THYSTAME
};

enum class ReplyType {
	STATUS,
	LOOK,
	INVENTORY,
	NUMBER,
	DEAD,
	ELEVATION,
	DISCARDED,
	UDEF,
};

class Player {
public:
	Player(ILink &link);
	~Player();

	void doAction(Action act, bool prioritise = false);
	void doAction(Action act, Stone res, bool prioritise = false);
	void doAction(
		Action act, const std::string &str, bool prioritise = false);
	void offloadActions();

	// Getters
	std::vector<std::vector<std::string>> &getVision() noexcept
	{
		return _vision;
	}
	unsigned int getLevel() const noexcept
	{
		return _level;
	}
	std::string getAndPopMessage()
	{
		std::string tmp = _msgq.front();
		_msgq.pop();
		return tmp;
	}

private:
	void _pollReplies();
	void _processReplies();

	ReplyType _resolveReplyType(std::string);
	void _uponReplyPop();
	void _uponReplyLook();
	void _uponReplyInventory();
	void _uponReplyConnectnbr();
	void _uponReplyIncant();

	ILink			&_link;
	std::deque<Action>	_actionQueue;
	std::deque<std::string>	_paramQueue;
	std::queue<Action>	_sentActions;
	std::queue<std::string>	_replies;
	std::unordered_map<Action, std::function<void()>> _replyMap;
	std::queue<std::string>	_msgq;

	// General player data
	std::vector<std::vector<std::string>>	_vision;
	std::unordered_map<std::string, int>	_inventory;
	unsigned int				_level;

	static std::unordered_map<Action, std::string> __actionNames;
	static std::unordered_map<Stone, std::string> __stoneNames;
};

}
#endif /* !PLAYER_HPP_ */
