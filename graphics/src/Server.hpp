/*
** EPITECH PROJECT, 2018
** zappy
** File description:
** Server
*/

#ifndef SERVER_HPP_
	#define SERVER_HPP_

#include "Socket.hpp"
#include "Parser.hpp"
#include "Player.hpp"

/*
**	This class is used to get the server information
*/
namespace gi {
class Server {
public:
	Server(int ac, char **av);
	~Server();
	sf::Vector2f getMapSize();
	MapCoord &getMap();
	std::list<sf::Vector2f> &getIncatPos() noexcept {return _incantPos;};
	void setMap(MapCoord &map) noexcept {_map = map;};
	std::list<std::string> &getHints();
	void updateMap();
	void updatePlayer();
	std::list<Player> &getPlayerList() {return _playerlist;};
	void execCmd(const ParsingType &type, std::string &cmd);
	void processCmd();
protected:
private:
	MapCoord _map;
	Socket _sock;
	std::list<std::string> _interaction;
	std::list<Player> _playerlist;
	std::list<sf::Vector2f> _incantPos;
};
};

#endif /* !SERVER_HPP_ */
