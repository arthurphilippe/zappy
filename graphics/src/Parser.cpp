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
	FullMapDef::EGG,
};

static const std::unordered_map<std::string, ParsingType> _ParsingTypeDef = {
	{"pnw", ParsingType::PNW},
	{"ppo", ParsingType::PPO},
	{"pdi", ParsingType::PDI},
	{"bct", ParsingType::BCT},
	{"enw", ParsingType::ENW},
	{"pic", ParsingType::PIC},
	{"pie", ParsingType::PIE},
};

static const std::unordered_map<FullMapDef, ObjectType> _ObjTypeDef = {
	{FullMapDef::FOOD, ObjectType::FOOD},
	{FullMapDef::LINEMATE, ObjectType::LINEMATE},
	{FullMapDef::DERAUMERE, ObjectType::DERAUMERE},
	{FullMapDef::SIBUR, ObjectType::SIBUR},
	{FullMapDef::MENDIANE, ObjectType::MENDIANE},
	{FullMapDef::PHIRAS, ObjectType::PHIRAS},
	{FullMapDef::THYSTAME, ObjectType::THYSTAME},
	{FullMapDef::EGG, ObjectType::EGG},
};

Orientation Parser::getOri(const std::string &ori)
{
	if (!ori.compare("1"))
		return Orientation::NORTH;
	if (!ori.compare("2"))
		return Orientation::EAST;
	if (!ori.compare("3"))
		return Orientation::SOUTH;
	if (!ori.compare("4"))
		return Orientation::WEST;
	return Orientation::NORTH;
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

}
