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
	UNKNOW,
};

class Object {
public:
	Object(sf::Vector2i coord, std::list<ObjectType> typelist) : _coord(coord), _typelist(typelist) {}
	Object(sf::Vector2i coord) : _coord(coord) {}
	~Object() = default;
	sf::Vector2i &getCoord() {return _coord;};
	std::list<ObjectType> &getObjList() {return _typelist;};
private:
	sf::Vector2i _coord;
	std::list<ObjectType> _typelist;
};


};

#endif /* !OBJECT_HPP_ */
