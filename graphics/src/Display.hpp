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
	#include "Player.hpp"

namespace gi {

	constexpr float OFF_SET = 30;
	constexpr float TILESIZE = 50;
	constexpr float BUFFSIZE = 14;

class Display {
	public:
		Display();
		~Display();
		bool isRunning() noexcept;
		void clear() noexcept {_window.clear();}
		void refresh() noexcept {_window.display();};
		bool putItem(const ObjectType type = ObjectType::FOOD, int posX = 0, int posY = 0) noexcept;
		bool putItem(gi::Object &object) noexcept;
		bool putItem(MapCoord &object) noexcept;
		bool putPlayer(gi::Player &player) noexcept;
		bool putPlayer(std::list<gi::Player> &playerlist) noexcept;
		bool putIncant(std::list<sf::Vector2f> &pos) noexcept;
	private:
		sf::RenderWindow _window;
		std::unordered_map<gi::ObjectType, std::unique_ptr<gi::Item>> _ItemMap;
		std::unordered_map<gi::Orientation, std::unique_ptr<gi::Item>> _PlayerMap;
		std::list<std::unique_ptr<gi::Item>> _Misc;
};
}

#endif /* !DISPLAY_HPP_ */
