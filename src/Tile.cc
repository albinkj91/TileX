#include <iostream>
#include "Tile.h"

Tile::Tile(int const x,
		int const y,
		int const width,
		int const height,
		sf::Texture const& tex)
	:sf::Sprite{tex}, x{x}, y{y}, width{width}, height{height}
{}

sf::Vector2i Tile::vec() const
{
	return sf::Vector2i{x, y};
}
