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
#include "Color.hpp"


namespace gi {
Socket::Socket(const int ac, char **av)
	: _port(0), _machine("localhost"), _tv({1, 0})
{
	if (ac == 2) {
		_port = std::stoi(av[1]);
	} else if (ac == 3) {
		_machine = av[1];
		_port = std::stoi(av[2]);
	} else {
		throw std::runtime_error("Not Enough Arguments");
	}
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
	struct hostent *h;

	if ((h = gethostbyname(_machine.c_str())) == nullptr)
		throw std::runtime_error("Cannot connect the machine");
	struct in_addr **serv_char_ip;
	char *ip;
	serv_char_ip = (struct in_addr **) h->h_addr_list;
	ip = inet_ntoa(*serv_char_ip[0]);
	s_in.sin_family = AF_INET;
	s_in.sin_port = htons(_port);
	s_in.sin_addr.s_addr = inet_addr(ip);
	if (connect(_socket, (const struct sockaddr *) &s_in,
		sizeof(s_in)) == -1) {
		throw std::runtime_error("Cannot connect the socket");
	}
}

bool Socket::receive(std::string &data)
{
	static char buf[4096];

	memset(buf, 0, 4096);
	FD_ZERO(&_fd_read);
	FD_SET(_socket, &_fd_read);
	select(_socket + 1, &_fd_read, NULL, NULL, &_tv);
	if (FD_ISSET(_socket, &_fd_read)) {
		read(_socket, buf, 4095);
		data += buf;
		return true;
	};
	return false;
}

}
