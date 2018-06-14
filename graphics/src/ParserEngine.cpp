/*
** EPITECH PROJECT, 2018
** graphics
** File description:
** ParserEngine
*/

#include "ParserEngine.hpp"

namespace gi {

std::string ParserEngine::getStringFromArgNb(std::string string, int nb)
{
	for (int i = 0; i < nb; i++) {
		string.substr(string.find(" ") + 1, string.length());
	}
	string = string.substr(0, string.find(" "));
	return string;
}

}
