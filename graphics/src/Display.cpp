/*
** EPITECH PROJECT, 2018
** zappy
** File description:
** Display
*/

#include "Display.hpp"

gi::Display::Display()
	: _window(), _textureMap({{ItemType::FOOD, "./assets/bla.bmp"},
				 {ItemType::LINEMATE, "./assets/Linemate.bmp"},
				 {ItemType::DERAUMERE, "./assets/Deraumere.bmp"},
				 {ItemType::SIBUR, "./assets/Sibur.bmp"},
				 {ItemType::MENDIANE, "./assets/Mendiane.bmp"},
				 {ItemType::PHIRAS, "./assets/Phiras.bmp"},
				 {ItemType::THYSTAME, "./assets/Thystame.bmp"}})
{
	_window.create(sf::VideoMode(800, 600), "Zappy");
	_window.setFramerateLimit(60);
}

gi::Display::~Display()
{
	_window.close();
}
