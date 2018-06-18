/*
** EPITECH PROJECT, 2018
** zappy
** File description:
** Client's Processing
*/

#include <iostream>
#include "Processing.hpp"

namespace pl {

Processing::Processing()
{}

Processing::~Processing() noexcept
{}

bool Processing::checkWelcome(const std::string &welcome) const noexcept
{
	if (welcome != "WELCOME\n")
		return false;
	return true;
}

void Processing::coordinates(const std::string &coordinates,
	int &X, int &Y) noexcept
{
	std::string x;
	std::string y;
	size_t pos = coordinates.find("\n") + 1;
	x = coordinates.substr(pos, coordinates.find(" ") - pos);
	y = coordinates.substr(coordinates.find(" ") + 1,
		coordinates.find("\n", pos) - (coordinates.find(" ") + 1));
	X = std::stoi(x);
	Y = std::stoi(y);
}

void Processing::vision(const std::string &response,
	std::vector<std::string> &vision) const noexcept
{
	std::string info;

	size_t beginPos = 0;
	size_t endPos = response.find(",");
	while (beginPos != std::string::npos) {
		info = response.substr(beginPos + 1, endPos - (beginPos + 1));
		info = info.substr(0, info.find("]"));
		if (info == "")
			info = "empty";
		vision.push_back(info);
		beginPos = endPos;
		endPos = response.find(",", endPos + 1);
	}
}

}