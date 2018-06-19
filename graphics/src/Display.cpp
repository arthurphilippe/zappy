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
	_ItemMap.insert(std::make_pair(ObjectType::FOOD, std::unique_ptr<gi::Item>(new Item("./assets/Food.png"))));
	_ItemMap.insert(std::make_pair(ObjectType::LINEMATE, std::unique_ptr<gi::Item>(new Item("./assets/Linemate.png"))));
	_ItemMap.insert(std::make_pair(ObjectType::DERAUMERE, std::unique_ptr<gi::Item>(new Item("./assets/Deraumere.png"))));
	_ItemMap.insert(std::make_pair(ObjectType::SIBUR, std::unique_ptr<gi::Item>(new Item("./assets/Sibur.png"))));
	_ItemMap.insert(std::make_pair(ObjectType::MENDIANE, std::unique_ptr<gi::Item>(new Item("./assets/Mendiane.png"))));
	_ItemMap.insert(std::make_pair(ObjectType::PHIRAS, std::unique_ptr<gi::Item>(new Item("./assets/Phiras.png"))));
	_ItemMap.insert(std::make_pair(ObjectType::THYSTAME, std::unique_ptr<gi::Item>(new Item("./assets/Thystame.png"))));
	_ItemMap.insert(std::make_pair(ObjectType::TILESET, std::unique_ptr<gi::Item>(new Item("./assets/Tileset.png"))));
	_PlayerMap.insert(std::make_pair(Orientation::EAST, std::unique_ptr<gi::Item>(new Item("./assets/right/1.png"))));
	_PlayerMap.insert(std::make_pair(Orientation::NORTH, std::unique_ptr<gi::Item>(new Item("./assets/back/1.png"))));
	_PlayerMap.insert(std::make_pair(Orientation::WEST, std::unique_ptr<gi::Item>(new Item("./assets/left/1.png"))));
	_PlayerMap.insert(std::make_pair(Orientation::SOUTH, std::unique_ptr<gi::Item>(new Item("./assets/front/1.png"))));
	_window.create(sf::VideoMode(1280, 720), "Zappy - But graphical <3");
	_window.setFramerateLimit(60);
}

gi::Display::~Display()
{
	_window.close();
}

bool gi::Display::isRunning() noexcept
{
	bool ret = _window.isOpen();
	sf::Event event;

	_window.pollEvent(event);
	if (event.type == sf::Event::Closed || sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
		ret = false;
	return ret;
}

bool gi::Display::putItem(const ObjectType type, const int posX, const int posY) noexcept
{
	auto match = _ItemMap.find(type);

	if (match == _ItemMap.end())
		return false;
	auto sprite = match->second->getSprite();
	sprite.setPosition(posX, posY);
	_window.draw(sprite);
	return true;
}

#include <iostream>
bool gi::Display::putItem(gi::Object &object) noexcept
{
	auto list = object.getObjList();
	auto tilematch = _ItemMap.find(ObjectType::TILESET);
	auto tileset = tilematch->second->getSprite();
	int x = 0;
	int y = 0;
	sf::Vector2f pos = object.getCoord();
	pos.x = TILESIZE + (TILESIZE * pos.x);
	pos.y = TILESIZE + (TILESIZE * pos.y);
	tileset.setOrigin(25, 25);
	tileset.setPosition(pos);
	_window.draw(tileset);
	pos.x -= (TILESIZE / 2) + (BUFFSIZE / 2);
	pos.y -= (TILESIZE / 2) + (BUFFSIZE / 2);
	for (auto i = list.begin(); i != list.end(); i++) {
		auto match = _ItemMap.find(*i);
		pos.x += (BUFFSIZE * x);
		if ((pos.y + (BUFFSIZE * y) > TILESIZE)) {
			y++;
			x = 0;
		}
		if (match == _ItemMap.end())
			return false;
		auto sprite = match->second->getSprite();
		sprite.setPosition(pos.x, pos.y);
		_window.draw(sprite);
		++x;
	}
	return true;
}

bool gi::Display::putPlayer(gi::Player &player) noexcept
{
	auto playermatch = _PlayerMap.find(player.getOri());
	auto spr = playermatch->second->getSprite();
	sf::Vector2f pos = player.getPos();
	pos.x = TILESIZE + (TILESIZE * pos.x);
	pos.y = TILESIZE + (TILESIZE * pos.y);
	spr.setOrigin(68, 90);
	spr.setPosition(pos);
	_window.draw(spr);
	return true;
}


bool gi::Display::putPlayer(std::list<gi::Player> &player) noexcept
{
	for (auto i = player.begin(); i != player.end(); i++) {
		putPlayer(*i);
	}
	return true;
}


bool gi::Display::putItem(MapCoord &object) noexcept
{
	bool ret = true;

	for (auto it = object.begin(); it != object.end(); it++) {
		auto hasFailed = putItem(*it);
		if (!hasFailed)
			ret = hasFailed;
	}
	return ret;
}
