#include <iostream>
#include "Tile.h"

Tile::Tile(float x, float y, float width, float height)
	:x{x}, y{y}, width{width}, height{height}
{}

sf::Vector2f Tile::vec() const
{
	return sf::Vector2f{x, y};
}
