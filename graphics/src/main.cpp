/*
** EPITECH PROJECT, 2018
** zappy
** File description:
** main
*/

#include "Socket.hpp"
#include "Display.hpp"
#include "Object.hpp"

int main(int ac, char **av)
{
	// gi::Socket sock(ac, av);
	// sock<<"Telnet Answer please";
	// while(1){sock.receive();};
	gi::Display display;

	display.putItem(gi::ItemType::LINEMATE, 40, 100);
	display.putItem(gi::ItemType::LINEMATE, 200, 400);
	while (display.isRunning())
		display.refresh();
}
