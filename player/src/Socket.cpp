/*
** EPITECH PROJECT, 2018
** zappy
** File description:
** Socket
*/

#include <cstring>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <netdb.h>
#include "Socket.hpp"
#include "color.h"


namespace pl {
Socket::Socket(const int ac, char **av)
	: _port(0), _machine("localhost"), _tv({1, 0})
{
	if (ac >= 2)
		_port = std::stoi(av[1]);
	else
		throw std::runtime_error("Not Enough Arguments");
	createSocket();
	connectSocket();
}

Socket::Socket()
	: _port(0), _machine("localhost"), _tv({1, 0})
{
	createSocket();
}

Socket::~Socket()
{
	close(_socket);
}

void Socket::operator<<(const std::string &string)
{
	std::cout << "Sending to server :" << ANSI_BOLD_COLOR_MAGENTA << string << ANSI_BOLD_COLOR_RESET << std::endl;
	if (write(_socket, string.c_str(), string.length()) == -1)
		throw std::runtime_error("Cannot write on socket");
}

void Socket::operator<<(const int i)
{
	std::string str(std::to_string(i));
	if (write(_socket, str.c_str(), str.length()) == -1)
		throw std::runtime_error("Cannot write on socket");
}

void Socket::createSocket()
{
	_socket = socket(AF_INET, SOCK_STREAM, 0);
	if (!_socket)
		throw std::runtime_error("Cannot create a socket");
}

void Socket::connectSocket()
{
	struct sockaddr_in s_in;

	s_in.sin_family = AF_INET;
	s_in.sin_port = htons(_port);
	s_in.sin_addr.s_addr = INADDR_ANY;
	if (connect(_socket, (const struct sockaddr *) &s_in,
		sizeof(s_in)) == -1) {
		throw std::runtime_error("Cannot connect the socket");
	}
}

bool Socket::tryToRead(std::string &data)
{
	static char buf[4096];

	memset(buf, 0, 4096);
	FD_ZERO(&_fd_read);
	FD_SET(_socket, &_fd_read);
	select(_socket + 1, &_fd_read, NULL, NULL, &_tv);
	if (FD_ISSET(_socket, &_fd_read)) {
		read(_socket, buf, 4095);
		data = buf;
		return true;
	};
	return false;
}

}
