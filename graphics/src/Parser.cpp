/*
** EPITECH PROJECT, 2018
** zappy
** File description:
** Parser
*/

#include <SFML/Graphics.hpp>
#include <unordered_map>
#include "Parser.hpp"
#include "ParserEngine.hpp"
#include "Object.hpp"

namespace gi {

static const std::vector<FullMapDef> _FullMapObjDef = {
	FullMapDef::FOOD,
	FullMapDef::LINEMATE,
	FullMapDef::DERAUMERE,
	FullMapDef::SIBUR,
	FullMapDef::MENDIANE,
	FullMapDef::PHIRAS,
	FullMapDef::THYSTAME,
};

static const std::unordered_map<std::string, ParsingType> _ParsingTypeDef = {
	{"pnw", ParsingType::PNW},
	{"ppo", ParsingType::PPO},
};

static const std::unordered_map<FullMapDef, ObjectType> _ObjTypeDef = {
	{FullMapDef::FOOD, ObjectType::FOOD},
	{FullMapDef::LINEMATE, ObjectType::LINEMATE},
	{FullMapDef::DERAUMERE, ObjectType::DERAUMERE},
	{FullMapDef::SIBUR, ObjectType::SIBUR},
	{FullMapDef::MENDIANE, ObjectType::MENDIANE},
	{FullMapDef::PHIRAS, ObjectType::PHIRAS},
	{FullMapDef::THYSTAME, ObjectType::THYSTAME},
};

MapCoord Parser::parseCmd(std::vector<std::string> &cmd, const ParsingType type) {
	switch (type) {
	case ParsingType::FULL_MAP:
		return (parseFullMap(cmd));
		break;
	case ParsingType::TILE_CONTENT:
		break;
	default:
		break;
	}
}

ParsingType Parser::getParsingType(const std::string type)
{
	for (auto i = _ParsingTypeDef.begin(); i != _ParsingTypeDef.end(); i++) {
		if (i->first == type)
			return (i->second);
	}
	return ParsingType::UNKNOW;
}

ParsingType Parser::getCmdType(std::string &cmd)
{
	auto vec = ParserEngine::createVectorString(cmd, ' ');
	if (!vec.size())
		return ParsingType::UNKNOW;
	auto parse = getParsingType(vec[0]);
	return parse;
}


ObjectType Parser::getObjType(const FullMapDef def)
{
	for (auto i = _ObjTypeDef.begin(); i != _ObjTypeDef.end(); i++) {
		if (i->first == def)
			return (i->second);
	}
	return ObjectType::UNKNOW;
}



MapCoord Parser::parseFullMap(std::vector<std::string> &cmd)
{
	MapCoord map;
	std::list<ObjectType> objlist;
	for (auto i = cmd.begin(); i != cmd.end(); i++) {
		if (i->length()) {
		int x = std::stoi(ParserEngine::getStringFromArgNb((*i),
			static_cast<int>(FullMapDef::COORD_X)));
		int y = std::stoi(ParserEngine::getStringFromArgNb((*i),
			static_cast<int>(FullMapDef::COORD_Y)));
		for (auto u = _FullMapObjDef.begin(); u != _FullMapObjDef.end(); u++) {
			int blocks = std::stoi(ParserEngine::getStringFromArgNb((*i),
				static_cast<int>(*u)));
			if (blocks) {
				while (blocks > 0) {
					objlist.push_back(getObjType(*u));
					--blocks;
				}
			}
		}
	map.push_back(Object(sf::Vector2f(x,y), objlist));
	objlist.clear();
	}
	}
	return map;
}

}
