/*
** EPITECH PROJECT, 2018
** zappy
** File description:
** Server
*/

#include "Parser.hpp"
#include "ParserEngine.hpp"
#include "Server.hpp"
#include "Command.hpp"
#include "Color.hpp"

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

MapCoord &Server::getMap()
{
	return _map;
}

sf::Vector2f Server::getMapSize()
{
	_sock << "msz\n";
	std::string ret;
	sf::Vector2f pos;
	if (_sock.receive(ret)) {
		auto vec = ParserEngine::createVectorString(ret, ' ');
		if (vec.size() >= 3) {
			pos.x = std::stoi(vec[1]);
			pos.y = std::stoi(vec[2]);
			return pos;
		}
	} else
		throw std::runtime_error("Can't get Map Size");
	return pos;
}

void Server::execCmd(const ParsingType &type, std::string &cmd)
{
	std::cout << BOLD_COLOR_YELLOW << "ZappyGi:: " << BOLD_COLOR_RESET
	<< BOLD_COLOR_GREEN << "processing: '" << BOLD_COLOR_RESET << cmd << BOLD_COLOR_GREEN << "'"  << std::endl;
	switch (type) {
	case ParsingType::PNW:
		Command::addNewPlayer(cmd, _playerlist);
		break;
	case ParsingType::PDI:
		Command::delPlayer(cmd, _playerlist);
		break;
	case ParsingType::BCT:
		Command::updateTile(cmd, _map);
	default:
		return;
	}
}

void Server::processCmd()
{
	for (auto i = _interaction.begin(); i != _interaction.end(); i++) {
		auto func_type = Parser::getCmdType(*i);
		auto cmd = *i;
		if (cmd[cmd.length() - 1] == '\n')
			cmd[cmd.length() - 1] = '\0';
		execCmd(func_type, cmd);
		_interaction.pop_front();
		i = _interaction.begin();
		if (i == _interaction.end())
			return;
	}
}

void Server::updateMap(MapCoord &map)
{
	int z = 0;
	for (auto i = map.begin(); i != map.end(); i++) {
		std::string str("bct");
		str += " ";
		auto pos = i->getCoord();
		str += std::to_string(static_cast<int> (pos.x));
		str += " ";
		str += std::to_string(static_cast<int> (pos.y));
		str += "\n";
		_sock << str;
		if (z > 10) {
			getHints();
			processCmd();
			z = 0;
		}
		z++;
	}
}

std::list<std::string> &Server::getHints()
{
	std::string str;
	if (_sock.isBlocking())
		_sock.setBlocking(false);
	if (_sock.receive(str)) {
		while (str.length()) {
			_interaction.push_back(ParserEngine::extractFirstString(str));
		}
	}
	return _interaction;
}

}
