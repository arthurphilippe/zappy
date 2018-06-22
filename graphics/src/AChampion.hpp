/*
** EPITECH PROJECT, 2018
** graphics
** File description:
** IChampion
*/

#ifndef ACHAMPION_HPP_
	#define ACHAMPION_HPP_
	#include <SFML/Graphics.hpp>

namespace gi
{

class AChampion {
public:
	AChampion(sf::Vector2f pos, unsigned int id) : _pos(pos), _id(id) {}
	~AChampion() = default;
	sf::Vector2f &getPos() noexcept {return _pos;};
	void setPos(float x, float y) {_pos.x = x; _pos.y = y;};
	void setPos(sf::Vector2f vec) {_pos = vec;};
	unsigned int &getID() noexcept {return _id;};

protected:
	sf::Vector2f _pos;
	unsigned int _id;

};

}

#endif /* !ICHAMPION_HPP_ */
