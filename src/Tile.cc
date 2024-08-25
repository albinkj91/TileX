#include <iostream>
#include "Tile.h"

Tile::Tile(float const x,
		float const y,
		float const width,
		float const height,
		sf::Texture const& tex)
	:sf::Sprite{tex}, x{x}, y{y}, width{width}, height{height}
{}

sf::Vector2f Tile::vec() const
{
	return sf::Vector2f{x, y};
}
