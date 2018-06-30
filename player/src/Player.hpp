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

class Player {
public:
	Player(ILink &link);
	~Player();

	void doAction(Action act, bool prioritise = false);
	void doAction(Action act, Stone res, bool prioritise = false);
	void doAction(
		Action act, const std::string &str, bool prioritise = false);
	void offloadActions();
	void pollReplies();

	// Getters
	std::vector<std::vector<std::string>> &getVision() noexcept
	{
		return _vision;
	}
	std::unordered_map<std::string, int> &getInventory() noexcept
	{
		return _inventory;
	}
	bool hasVisionChanged() noexcept
	{
		auto ret = _hasVisionChanged;
		_hasVisionChanged = false;
		return ret;
	}
	bool hasInventoryChanged() noexcept
	{
		auto ret = _hasInventoryChanged;
		_hasInventoryChanged = false;
		return ret;
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
	unsigned int getPendingActionCount() const noexcept
	{
		return _sentActions.size() + _actionQueue.size();
	}

private:
	void _processReplies();

	// upon reply functors
	void _uponReplyPop();
	void _uponReplyLook();
	void _uponReplyInventory();
	void _uponReplyConnectnbr();
	void _uponReplyIncant();

	// Inner workings of the player
	ILink			&_link;
	std::deque<Action>	_actionQueue;
	std::deque<std::string>	_paramQueue;
	std::queue<Action>	_sentActions;
	std::queue<std::string>	_replies;
	std::unordered_map<Action, std::function<void()>> _replyMap;
	std::queue<std::string>	_msgq;

	// General player data
	std::vector<std::vector<std::string>>	_vision;
	bool					_hasVisionChanged;
	std::unordered_map<std::string, int>	_inventory;
	bool					_hasInventoryChanged;
	unsigned int				_level;

	// Static maps
	static std::unordered_map<Action, std::string> __actionNames;
	static std::unordered_map<Stone, std::string> __stoneNames;
};

}
#endif /* !PLAYER_HPP_ */
