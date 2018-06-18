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

void AI::look(Socket &socket, const Processing &processing)
{
	std::string response;

	this->clearVision();
	socket << "Look";
	while (!socket.tryToRead(response));
	processing.vision(response, _vision);
}

void AI::clearVision()
{
	while (!_vision.empty()) {
		_vision.pop_back();
	}
}

}