/*
** EPITECH PROJECT, 2018
** graphics
** File description:
** Command
*/

#include <iostream>
#include "ParserEngine.hpp"
#include "Command.hpp"

namespace gi {

void Command::addNewPlayer(std::string &cmd, std::list<Player> &playerlist)
{
	auto vec = ParserEngine::createVectorString(cmd, ' ');
	if (vec.size() != 7)
		return;
	std::cout << "YEAY" << std::endl;
}

void Command::delPlayer(std::string &cmd, std::list<Player> &playerlist)
{
	auto vec = ParserEngine::createVectorString(cmd, ' ');
	if (vec.size() != 2)
		return;
	for (auto i = playerlist.begin(); i != playerlist.end(); i++) {
		if (std::to_string(i->getID()) == vec[1]) {
			playerlist.erase(i);
			return;
		}

	}
}

}
