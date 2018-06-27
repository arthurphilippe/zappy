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

private:
	void _pollReplies();
	void _processReplies();

	void _uponReplyPop();

	ILink			&_link;
	std::deque<Action>	_actionQueue;
	std::deque<std::string>	_paramQueue;
	std::queue<Action>	_sentActions;
	std::queue<std::string>	_replies;
	unsigned int		_level;
	std::unordered_map<ReplyType, std::function<void()>> __replyMap;

	static std::unordered_map<Action, std::string> __actionNames;
	static std::unordered_map<Stone, std::string> __stoneNames;
};

}
#endif /* !PLAYER_HPP_ */
