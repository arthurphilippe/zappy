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
	switch (type) {
	case ParsingType::PNW:
		Command::addNewPlayer(cmd, _playerlist);
		break;
	case ParsingType::PDI:
		Command::delPlayer(cmd, _playerlist);
		break;
	case ParsingType::BCT:
		Command::updateTile(cmd, _map);
		break;
	case ParsingType::PPO:
		Command::movePlayer(cmd, _playerlist);
		break;
	case ParsingType::ENW:
		Command::addEgg(cmd, _map);
		break;
	case ParsingType::PIC:
		Command::beginIncant(cmd, _incantPos);
		break;
	case ParsingType::PIE:
		Command::endIncant(cmd, _incantPos);
		break;
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

void Server::updatePlayer()
{
	for (auto i = _playerlist.begin(); i != _playerlist.end(); i++) {
		if (i->getOri() != Orientation::DEAD) {
			std::string str("ppo");
			str += " ";
			str += std::to_string(i->getID());
			str += "\n";
			_sock << str;
		}
	}
}

void Server::updateMap()
{
	_sock << "mct\n";
}

std::list<std::string> &Server::getHints()
{
	std::string str;
	if (_sock.isBlocking())
		_sock.setBlocking(false);
	if (_sock.receive(str)) {
		while (str.length() && std::count(str.begin(), str.end(), '\n')) {
			_interaction.push_back(ParserEngine::extractFirstString(str));
		}
	}
	if (str.length()) {
		_interaction.push_back(str);
	}
	return _interaction;
}

}
