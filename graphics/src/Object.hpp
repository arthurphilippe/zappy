/*
** EPITECH PROJECT, 2018
** zappy
** File description:
** Objects
*/

#ifndef OBJECT_HPP_
	#define OBJECT_HPP_

	#include <list>
	#include <SFML/Graphics.hpp>

namespace gi {

enum class ObjectType {
	PLAYER,
	FOOD,
	LINEMATE,
	DERAUMERE,
	SIBUR,
	MENDIANE,
	PHIRAS,
	THYSTAME,
	TILESET,
	UNKNOW,
};

class Object {
public:
	Object(sf::Vector2f coord, std::list<ObjectType> &typelist) : _coord(coord), _typelist(typelist) {}
	Object(sf::Vector2f coord) : _coord(coord) {}
	~Object() = default;
	sf::Vector2f &getCoord() {return _coord;};
	std::list<ObjectType> &getObjList() {return _typelist;};
private:
	sf::Vector2f _coord;
	std::list<ObjectType> _typelist;
};

using MapCoord = std::list<Object>;

};

#endif /* !OBJECT_HPP_ */
