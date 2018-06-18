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
		bool putItem(const ObjectType type = ObjectType::FOOD, int posX = 0, int posY = 0) noexcept;
		bool putItem(gi::Object &object) noexcept;
		bool putItem(std::vector<gi::Object> &object) noexcept;
	private:
		sf::RenderWindow _window;
		std::unordered_map<gi::ObjectType, std::unique_ptr<gi::Item>> _ItemMap;
};
}

#endif /* !DISPLAY_HPP_ */
