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
		std::vector<Object> getMap() const noexcept {return _map;};
	private:
		std::vector<Object> _map;
	};
}

#endif /* !DISPLAY_HPP_ */
