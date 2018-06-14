/*
** EPITECH PROJECT, 2018
** zappy
** File description:
** SFML Display Class
*/

#ifndef DISPLAY_HPP_
	#define DISPLAY_HPP_

	#include <unordered_map>
	#include <SFML/Graphics.hpp>
	#include "Object.hpp"

namespace gi {

class Display {
	public:
		Display();
		~Display();
		bool isRunning() const noexcept {return _window.isOpen();};
	private:
		sf::Window					_window;
		std::unordered_map<gi::ItemType, std::string>	_ItemMap;
};
}

#endif /* !DISPLAY_HPP_ */
