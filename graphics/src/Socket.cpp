/*
** EPITECH PROJECT, 2018
** zappy
** File description:
** Socket
*/

#include <cstring>
#include "Socket.hpp"

namespace gi {
Socket::Socket(const int ac, char **av)
	: _ip("0.0.0.0"), _port(0)
{
	if (ac == 2) {
		_port = std::stoi(av[1]);
	} else if (ac == 3) {
		_ip = av[1];
		if (!std::count(_ip.begin(), _ip.end(), '.'))
			throw std::runtime_error("Invalid IP: got " + _ip);
		_port = std::stoi(av[2]);
	} else {
		throw std::runtime_error("Not Enough Arguments");
	}
	connect();
}

void Socket::connect()
{
	sf::Socket::Status status = _socket.connect(_ip, _port);
	if (status != sf::Socket::Done)
		throw std::runtime_error("Can't Connect to IP");
	_socket.setBlocking(false);
}

bool Socket::send(const std::string &string)
{
	size_t len = 0;
	if (_socket.send(string.c_str(), (sizeof(const char) * string.length()), len) != sf::Socket::Done)
		throw std::runtime_error("Can't send data on socket");
	if (len != string.length())
		throw std::runtime_error("Send not completed");
	return (true);
}

bool Socket::send(const int &i)
{
	size_t len = 0;
	std::string str(std::to_string(i));
	if (_socket.send(str.c_str(), (sizeof(const char) * str.length()), len) != sf::Socket::Done)
		throw std::runtime_error("Can't send data on socket");
	if (len != str.length())
		throw std::runtime_error("Send not completed");
	return (true);
}

bool Socket::receive()
{
	char data[8192];
	size_t len;

	memset(data, '\0', 8192);
	_socket.receive(data, 8192, len);
	if (len)
		std::cout << data << std::endl;
	return (true);
}

}
