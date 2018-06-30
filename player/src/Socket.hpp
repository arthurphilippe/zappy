/*
** EPITECH PROJECT, 2018
** zappy
** File description:
** Socket
*/

#ifndef SOCKET_HPP_
	#define SOCKET_HPP_

	#include <iostream>
	#include "ILink.hpp"

namespace pl {

class Socket : public ILink {
public:
	Socket(const int ac, char **av);
	Socket();
	~Socket();
	void operator<<(const std::string &string) override;
	void operator<<(const int i) override;
	bool read(std::string &buff) override;
	void connectSocket();
	void setPort(int port)
	{
		_port = port;
	}
	void setMachine(const std::string &machine)
	{
		_machine = machine;
	}
private:
	void createSocket();
	int		_socket;
	int 		_port;
	std::string	_machine;
	fd_set		_fd_read;
	struct timeval	_tv;
};
}

#endif /* !SOCKET_HPP_ */
