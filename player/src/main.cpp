/*
** EPITECH PROJECT, 2018
** zappy
** File description:
** player's main
*/

#include "Socket.hpp"
#include "unistd.h"

int main(int ac, char **av)
{
	std::string data;
	pl::Socket s(ac, av);
	s << "papou";
	while (!s.tryToRead(data));
	std::cout << data;
	while (!s.tryToRead(data));
	std::cout << data;
	return 0;
}