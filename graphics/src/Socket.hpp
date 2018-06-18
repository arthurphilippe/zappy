/*
** EPITECH PROJECT, 2018
** zappy
** File description:
** Socket
*/

#ifndef SOCKET_HPP_
	#define SOCKET_HPP_

	#include <SFML/Network.hpp>
	#include <iostream>
	#include <vector>

namespace gi {
class Socket {
public:
	Socket(const int ac, char **av);
	~Socket() {};
	void operator<<(const std::string &string) {send(string);}
	void operator<<(const int &i) {send(i);}
	bool receive(std::string &string);
	bool receive();
protected:
private:
	void connect();
	bool send(const std::string &string);
	bool send(const int &i);
	sf::TcpSocket _socket;
	std::string _ip;
	std::vector<std::string> _servMsg;
	int _port;
};
}

#endif /* !SOCKET_HPP_ */
