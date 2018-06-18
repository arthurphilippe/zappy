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
	std::cout << welcome << "##";
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

}