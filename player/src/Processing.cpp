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

void Processing::vision(const std::string &reply,
	std::vector<std::vector<std::string>> &vision) const noexcept
{
	std::string info;

	size_t beginPos = 0;
	size_t endPos = reply.find(",");
	while (beginPos != std::string::npos) {
		info = reply.substr(beginPos + 1, endPos - (beginPos + 1));
		info = info.substr(0, info.find("]"));
		if (info.find(" ") == 0)
			info = info.substr(1);
		if (info == "")
			info = "empty";
		parseTileContent(info, vision);
		beginPos = endPos;
		endPos = reply.find(",", endPos + 1);
	}
}

void Processing::inventory(const std::string &reply,
	std::unordered_map<std::string, int> &inventory) const
{
	std::string info;

	size_t beginPos = 0;
	size_t endPos = reply.find(",");
	while (beginPos != std::string::npos) {
		info = reply.substr(beginPos + 1, endPos - (beginPos + 1));
		info = info.substr(0, info.find("]"));
		if (info != "" && info != " ")
			this->parseResources(info, inventory);
		beginPos = endPos;
		endPos = reply.find(",", endPos + 1);
	}
}

void Processing::parseTileContent(std::string &content,
	std::vector<std::vector<std::string>> &vision) const
{
	std::vector<std::string> tile;
	std::string item;
	if (content == "empty") {
		vision.push_back(tile);
		return;
	}
	size_t beginPos = 0;
	size_t endPos = content.find(" ");
	while (beginPos != std::string::npos) {
		item = content.substr(beginPos, endPos - beginPos);
		if (item.find(" ") == 0)
			item = item.substr(1);
		tile.push_back(item);
		beginPos = endPos;
		endPos = content.find(" ", endPos + 1);
	}
	vision.push_back(tile);
}

void Processing::parseResources(std::string &info,
	std::unordered_map<std::string, int> &inventory) const
{
	if (info.find(" ") == 0)
		info = info.substr(1);
	std::string resource = info.substr(0, info.find(" "));
	int amount = std::stoi(info.substr(info.find(" ") + 1));
	inventory[resource] = amount;
}

bool Processing::catchMessage(const std::string &reply) const
{
	if (reply.substr(0, reply.find(" ")) == "message")
		return true;
	return false;
}

}