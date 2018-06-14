/*
** EPITECH PROJECT, 2018
** graphics
** File description:
** ParserEngine
*/

#include <algorithm>
#include "ParserEngine.hpp"

namespace gi {
std::string ParserEngine::getStringFromArgNb(std::string string, int nb)
{

	int total = std::count(string.begin(), string.end(), ' ');
	if (!total)
		return string;
	for (int i = 0; i < (total - nb); i++) {
		string  = string.substr(0, string.find_last_of(" "));
	}
	string = string.substr(string.find_last_of(" ") + 1, string.length());
	return string;
}

}
