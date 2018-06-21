/*
** EPITECH PROJECT, 2018
** graphics
** File description:
** Command
*/

#include <iostream>
#include "ParserEngine.hpp"
#include "Command.hpp"
#include "Parser.hpp"
#include "ParserEngine.hpp"

namespace gi {

void Command::movePlayer(std::string &cmd, std::list<Player> &playerlist)
{
	auto vec = ParserEngine::createVectorString(cmd, ' ');
	if (vec.size() != 5)
		return;
	for (auto i = playerlist.begin(); i != playerlist.end(); i++) {
		if (std::to_string(i->getID()) == vec[1]) {
			i->setPos(sf::Vector2f(std::stof(vec[2]), std::stof(vec[3])));
			i->setOri(Parser::getOri(vec[4]));
		}
	}
}

void Command::addNewPlayer(std::string &cmd, std::list<Player> &playerlist)
{
	auto vec = ParserEngine::createVectorString(cmd, ' ');
	if (vec.size() != 7)
		return;
	for (auto i = playerlist.begin(); i != playerlist.end(); i++) {
		if (i->getID() == std::stol(vec[1]))
			return;
	}
	playerlist.push_back(Player(sf::Vector2f(std::stoi(vec[2]), std::stoi(vec[3])), Parser::getOri(vec[4]), vec[6], std::stoi(vec[1])));
}

void Command::delPlayer(std::string &cmd, std::list<Player> &playerlist)
{
	auto vec = ParserEngine::createVectorString(cmd, ' ');
	if (vec.size() != 2)
		return;
	for (auto i = playerlist.begin(); i != playerlist.end(); i++) {
		if (std::to_string(i->getID()) == vec[1]) {
			i->setOri(Orientation::DEAD);
			return;
		}

	}
}
static const std::vector<FullMapDef> _FullMapObjDef = {
	FullMapDef::FOOD,
	FullMapDef::LINEMATE,
	FullMapDef::DERAUMERE,
	FullMapDef::SIBUR,
	FullMapDef::MENDIANE,
	FullMapDef::PHIRAS,
	FullMapDef::THYSTAME,
};

void Command::updateTile(std::string &cmd, MapCoord &map)
{
	auto vec = ParserEngine::createVectorString(cmd, ' ');
	if (vec.size() != 10)
		return;
	bool empty = true;
	int x = std::stoi(vec[1]);
	int y = std::stoi(vec[2]);
	for (auto i = map.begin(); i != map.end(); i++) {
		if (i->getCoord().x == x && i->getCoord().y == y) {
			i->getObjList().clear();
			for (auto u = _FullMapObjDef.begin(); u != _FullMapObjDef.end(); u++) {
			int blocks = std::stoi(ParserEngine::getStringFromArgNb(cmd,
				static_cast<int>(*u)));
			if (blocks) {
				while (blocks > 0) {
					i->getObjList().push_back(Parser::getObjType(*u));
					--blocks;
				}
				empty = false;
			}
			}
		}
		}
}

}
