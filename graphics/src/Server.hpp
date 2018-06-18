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

/*
**	This class is used to get the server information
*/
namespace gi {
class Server {
public:
	Server(int ac, char **av);
	~Server();
	MapCoord getMap();
protected:
private:
	MapCoord _map;
	Socket _sock;
};
};

#endif /* !SERVER_HPP_ */
