/*
** EPITECH PROJECT, 2018
** zappy
** File description:
** Display
*/

#include "Display.hpp"

gi::Display::Display()
	: _window()
{
	_ItemMap.insert(std::make_pair(ItemType::FOOD, std::unique_ptr<gi::Item>(new Item("./assets/Linemate.png"))));
	_ItemMap.insert(std::make_pair(ItemType::LINEMATE, std::unique_ptr<gi::Item>(new Item("./assets/Linemate.png"))));
	_ItemMap.insert(std::make_pair(ItemType::DERAUMERE, std::unique_ptr<gi::Item>(new Item("./assets/Deraumere.png"))));
	_ItemMap.insert(std::make_pair(ItemType::SIBUR, std::unique_ptr<gi::Item>(new Item("./assets/Sibur.png"))));
	_ItemMap.insert(std::make_pair(ItemType::MENDIANE, std::unique_ptr<gi::Item>(new Item("./assets/Mendiane.png"))));
	_ItemMap.insert(std::make_pair(ItemType::PHIRAS, std::unique_ptr<gi::Item>(new Item("./assets/Phiras.png"))));
	_ItemMap.insert(std::make_pair(ItemType::THYSTAME, std::unique_ptr<gi::Item>(new Item("./assets/Thystame.png"))));
	_window.create(sf::VideoMode(800, 600), "Zappy - But graphical <3");
	_window.setFramerateLimit(60);
}

gi::Display::~Display()
{
	_window.close();
}

void gi::Display::putItem(const ItemType type, int posX, int posY) noexcept
{
	auto match = _ItemMap.find(type);

	if (match == _ItemMap.end())
		return;
	match->second->setPosition(_window, posX, posY);
}
