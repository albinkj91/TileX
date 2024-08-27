#include <iostream>
#include "Tile.h"

Tile::Tile(int const width,
		int const height,
		sf::Texture const& tex)
	:sf::Sprite{tex}, width{width}, height{height}
{}
