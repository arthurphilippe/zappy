/*
** EPITECH PROJECT, 2018
** graphics
** File description:
** Command
*/

#ifndef COMMAND_HPP_
	#define COMMAND_HPP_

	#include "Player.hpp"
	#include "Parser.hpp"

namespace gi {

class Command {
	public:
	Command() = delete;
	~Command() = delete;
	static void addNewPlayer(std::string &cmd, std::list<Player> &playerlist);
	static void delPlayer(std::string &cmd, std::list<Player> &playerlist);
	static void updateTile(std::string &cmd, MapCoord &map);
	protected:
	private:

};
}

#endif /* !COMMAND_HPP_ */
