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
	playerlist.push_back(Player(sf::Vector2f(std::stoi(vec[2]), std::stoi(vec[3])), Parser::getOri(vec[4]), vec[6], std::stoi(vec[1])));
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
