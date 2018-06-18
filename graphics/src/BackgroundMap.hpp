//
// EPITECH PROJECT, 2018
// zappy
// File description:
// background map header
//

#ifndef BACKGROUNDMAP_HPP_
	#define BACKGROUNDMAP_HPP_

	#include <vector>
	#include "Object.hpp"

namespace gi {

	class BackgroundMap {
	public:
		BackgroundMap(int x, int y, int tilesize);
		~BackgroundMap();
		MapCoord getMap() const noexcept {return _map;};
	private:
		MapCoord _map;
	};
}

#endif /* !DISPLAY_HPP_ */
