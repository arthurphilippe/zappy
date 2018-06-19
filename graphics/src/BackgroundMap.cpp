//
// EPITECH PROJECT, 2018
// zappy
// File description:
// background map file
//

#include "BackgroundMap.hpp"

namespace gi {

BackgroundMap::BackgroundMap(int x, int y)
{
	for (int i = 0; i < x; i++)
		for (int j = 0; j < y; j++)
			_map.push_back(Object(sf::Vector2f(i, j)));
}
BackgroundMap::~BackgroundMap()
{
}

}
