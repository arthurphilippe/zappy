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
	_ItemMap.insert(std::make_pair(ItemType::FOOD, std::unique_ptr<gi::Item>(new Item("./assets/Food.png"))));
	_ItemMap.insert(std::make_pair(ItemType::LINEMATE, std::unique_ptr<gi::Item>(new Item("./assets/Linemate.png"))));
	_ItemMap.insert(std::make_pair(ItemType::DERAUMERE, std::unique_ptr<gi::Item>(new Item("./assets/Deraumere.png"))));
	_ItemMap.insert(std::make_pair(ItemType::SIBUR, std::unique_ptr<gi::Item>(new Item("./assets/Sibur.png"))));
	_ItemMap.insert(std::make_pair(ItemType::MENDIANE, std::unique_ptr<gi::Item>(new Item("./assets/Mendiane.png"))));
	_ItemMap.insert(std::make_pair(ItemType::PHIRAS, std::unique_ptr<gi::Item>(new Item("./assets/Phiras.png"))));
	_ItemMap.insert(std::make_pair(ItemType::THYSTAME, std::unique_ptr<gi::Item>(new Item("./assets/Thystame.png"))));
	_window.create(sf::VideoMode(1280, 720), "Zappy - But graphical <3");
	_window.setFramerateLimit(60);
}

gi::Display::~Display()
{
	_window.close();
}

bool gi::Display::putItem(const ItemType type, const int posX, const int posY) noexcept
{
	auto match = _ItemMap.find(type);

	if (match == _ItemMap.end())
		return false;
	auto sprite = match->second->getSprite();
	sprite.setPosition(posX, posY);
	_window.draw(sprite);
	return true;
}

bool gi::Display::putItem(gi::Object &object) noexcept
{
	auto match = _ItemMap.find(object.getType());

	if (match == _ItemMap.end())
		return false;
	sf::Vector2i pos = object.getCoord();
	auto sprite = match->second->getSprite();
	sprite.setPosition(pos.x, pos.y);
	_window.draw(sprite);
	return true;
}

bool gi::Display::putItem(std::vector<gi::Object> &object) noexcept
{
	bool ret = true;

	for (auto it = object.begin(); it != object.end(); it++) {
		auto hasFailed = putItem(*it);
		if (!hasFailed)
			ret = hasFailed;
	}
	return ret;
}
