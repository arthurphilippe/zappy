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

	display.putItem(gi::ItemType::FOOD, 40, 40);
	display.putItem(gi::ItemType::LINEMATE, 40, 64);
	display.putItem(gi::ItemType::DERAUMERE, 40, 88);
	display.putItem(gi::ItemType::SIBUR, 40, 112);
	display.putItem(gi::ItemType::MENDIANE, 40, 136);
	display.putItem(gi::ItemType::PHIRAS, 40, 160);
	display.putItem(gi::ItemType::THYSTAME, 40, 184);
	while (display.isRunning())
		display.refresh();
}
