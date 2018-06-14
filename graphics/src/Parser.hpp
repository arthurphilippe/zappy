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

namespace gi {

using MapCoord = std::vector<Object>;
typedef enum ParsingType {
	FULL_MAP,
	TILE_CONTENT,
}		ParsingType;

class Parser {
	public:
		Parser() = delete;
		~Parser() = delete;
		static void parseCmd(std::vector<std::string> &cmd, ParsingType);
	protected:
	private:
		static MapCoord parseFullMap(std::vector<std::string> &cmd);
};
}

#endif /* !PARSER_HPP_ */
