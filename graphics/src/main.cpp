/*
** EPITECH PROJECT, 2018
** zappy
** File description:
** main
*/

#include "Socket.hpp"
#include "Display.hpp"

int main(int ac, char **av)
{
	// gi::Socket sock(ac, av);
	// sock<<"Telnet Answer please";
	// while(1){sock.receive();};
	gi::Display display;

	while (display.isRunning());
}
