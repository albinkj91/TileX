#include <iostream>
#include "Tile.h"

Tile::Tile(int const x, int const y, sf::Texture const& tex)
	:sprite{tex}, pos{x, y}
{}

void Tile::set_pos(int const x, int const y)
{
	pos = sf::Vector2i{x, y};
	sprite.setPosition(x, y);
}

sf::Vector2i Tile::get_pos() const
{
	return sf::Vector2i{pos.x, pos.y};
}

sf::Sprite Tile::get_sprite() const
{
	return sprite;
}
