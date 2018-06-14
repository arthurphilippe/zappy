/*
** EPITECH PROJECT, 2018
** zappy
** File description:
** Objects
*/

#ifndef OBJECT_HPP_
	#define OBJECT_HPP_

	#include <SFML/Graphics.hpp>

namespace gi {

enum ItemType {
	FOOD,
	LINEMATE,
	DERAUMERE,
	SIBUR,
	MENDIANE,
	PHIRAS,
	THYSTAME,
};

class Object {
public:
	Object(sf::Vector2i coord, ItemType type) : _coord(coord), _type(type) {}
	~Object() = default;
	sf::Vector2i &getCoord() {return _coord;};
	ItemType &getType() {return _type;};
private:
	sf::Vector2i _coord;
	ItemType _type;
};


};

#endif /* !OBJECT_HPP_ */
