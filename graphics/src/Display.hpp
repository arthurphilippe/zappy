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
	#include "Item.hpp"

namespace gi {

class Display {
	public:
		Display();
		~Display();
		bool isRunning() noexcept {return _window.isOpen();};
		void refresh() noexcept {_window.display();};
		void putItem(const ItemType type = ItemType::FOOD, int posX = 0, int posY = 0) noexcept;
	private:
		sf::RenderWindow _window;
		std::unordered_map<gi::ItemType, std::unique_ptr<gi::Item>> _ItemMap;
};
}

#endif /* !DISPLAY_HPP_ */
