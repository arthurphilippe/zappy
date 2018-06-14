/*
** EPITECH PROJECT, 2018
** zappy
** File description:
** Item
*/

#ifndef ITEM_HPP_
	#define ITEM_HPP_

	#include <memory>
	#include <SFML/Graphics.hpp>

namespace gi {
class Item {
	public:
		Item(const std::string &texturePath);
		~Item();
		void setPosition(sf::RenderWindow &window, const int x, const int y) noexcept;
		std::string &getTexturePath() noexcept {return _texturePath;};
	private:
		std::string			_texturePath;
		std::unique_ptr<sf::Sprite>	_sprite;
		std::unique_ptr<sf::Texture>	_texture;


};
}

#endif /* !ITEM_HPP_ */
