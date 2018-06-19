/*
** EPITECH PROJECT, 2018
** graphics
** File description:
** ParserEngine
*/

#include <algorithm>
#include <iostream>
#include "ParserEngine.hpp"

namespace gi {

std::string ParserEngine::extractFirstString(std::string &string)
{
	int total = std::count(string.begin(), string.end(), '\n');
	if (!total)
		return string;
	std::string tmp;
	tmp = string.substr(0, string.find_first_of('\n'));
	string = string.substr(string.find_first_of('\n') + 1, string.length());
	return tmp;
}

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

std::vector<std::string> ParserEngine::createVectorString(std::string string, char delim)
{
	int total = std::count(string.begin(), string.end(), delim);
	std::vector<std::string> vec;
	if (!total) {
		return vec;
	}
	vec.clear();
	while (std::count(string.begin(), string.end(), delim) >= 1) {
		unsigned long i = string.find(delim);
		if (i != std::string::npos) {
			std::string tmp = string.substr(0, i);
			vec.push_back(tmp);
			string = string.substr(i + 1, string.length());
		}
	}
	if (string.length() > 0) {
		vec.push_back(string);
	}
	return vec;
}

}

