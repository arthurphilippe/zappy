/*
** EPITECH PROJECT, 2018
** zappy
** File description:
** Parser
*/

#ifndef PARSER_HPP_
	#define PARSER_HPP_

	#include <SFML/Graphics.hpp>
	#include <map>
	#include <string>
	#include <vector>
	#include "Object.hpp"
	#include "Player.hpp"

namespace gi {

enum class FullMapDef {
	CMD,
	COORD_X,
	COORD_Y,
	FOOD,
	LINEMATE,
	DERAUMERE,
	SIBUR,
	MENDIANE,
	PHIRAS,
	THYSTAME,
	UNKNOW,
};

enum class ParsingType {
	FULL_MAP,
	TILE_CONTENT,
	PNW,
	PDI,
	PPO,
	BCT,
	UNKNOW,
};

class Parser {
	public:
		Parser() = delete;
		~Parser() = delete;
		static MapCoord parseCmd(std::vector<std::string> &cmd, const ParsingType);
		static ObjectType getObjType(const FullMapDef def);
		static ParsingType getCmdType(std::string &cmd);
		static ParsingType getParsingType(const std::string type);
		static Orientation getOri(const std::string &ori);
	protected:
	private:
		static MapCoord parseFullMap(std::vector<std::string> &cmd);
};
}

#endif /* !PARSER_HPP_ */

