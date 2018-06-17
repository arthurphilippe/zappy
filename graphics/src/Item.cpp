/*
** EPITECH PROJECT, 2018
** zappy
** File description:
** Item
*/

#include "Item.hpp"

gi::Item::Item(const std::string &texturePath)
	: _texturePath(texturePath), _sprite(), _texture()
{
	if (!_texture.loadFromFile(texturePath))
		throw std::runtime_error("No Texture found at: " + _texturePath);
	auto size = _texture.getSize();
	_sprite.setTexture(_texture);
	_sprite.setPosition(0,0);
	_sprite.setOrigin(size.x / 2, size.y / 2);
}

gi::Item::~Item()
{
}
