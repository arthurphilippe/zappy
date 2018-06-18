/*
** EPITECH PROJECT, 2018
** zappy
** File description:
** Server
*/

#include "Parser.hpp"
#include "ParserEngine.hpp"
#include "Server.hpp"

namespace gi {

Server::Server(int ac, char **av)
	: _sock(ac, av)
{
	_sock << "ZPPGFX88\n";
	_sock.receive();
}

Server::~Server()
{
}

MapCoord Server::getMap()
{
	_sock << "mct\n";
	std::string ret;
	_sock.receive(ret);
	auto vec = ParserEngine::createVectorString(ret, '\n');
	auto fullMap = Parser::parseCmd(vec, ParsingType::FULL_MAP);
	return fullMap;
}

}
