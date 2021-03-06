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
		sf::Sprite &getSprite() noexcept {return _sprite;};
		sf::Texture &getTexture() noexcept {return _texture;};
		std::string &getTexturePath() noexcept {return _texturePath;};
	private:
		std::string	_texturePath;
		sf::Sprite	_sprite;
		sf::Texture	_texture;
};
}

#endif /* !ITEM_HPP_ */
