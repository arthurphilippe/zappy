/*
** EPITECH PROJECT, 2018
** graphics
** File description:
** Egg
*/

#ifndef EGG_HPP_
	#define EGG_HPP_
	#include "AChampion.hpp"

namespace gi {

class Egg : public AChampion {
	public:
		Egg(sf::Vector2f pos, unsigned int id) : AChampion(pos, id) {}
		~Egg() = default;
};

}

#endif /* !EGG_HPP_ */
