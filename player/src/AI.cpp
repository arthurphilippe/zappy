/*
** EPITECH PROJECT, 2018
** zappy
** File description:
** Client's AI
*/

#include "AI.hpp"

namespace pl {

AI::AI()
{}

void AI::look(Socket &socket)
{
	std::string response;
	std::string info;

	this->clearVision();
	socket << "Look";
	while (!socket.tryToRead(response));
	size_t beginPos = 0;
	size_t endPos = response.find(",");
	while (beginPos != std::string::npos) {
		info = response.substr(beginPos + 1, endPos - (beginPos + 1));
		info = info.substr(0, info.find("]"));
		if (info == "")
			info = "empty";
		_vision.push_back(info);
		beginPos = endPos;
		endPos = response.find(",", endPos + 1);
	}
}

void AI::clearVision()
{
	while (!_vision.empty()) {
		_vision.pop_back();
	}
}

}