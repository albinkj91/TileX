#ifndef TILE_H
#define TILE_H

#include <SFML/Graphics.hpp>

class Tile : public sf::Sprite
{
public:
	Tile(int const width,
		int const height,
		sf::Texture const& tex);
private:
	int width;
	int height;
};

#endif
