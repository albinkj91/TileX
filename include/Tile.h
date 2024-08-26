#ifndef TILE_H
#define TILE_H

#include <SFML/Graphics.hpp>

class Tile : public sf::Sprite
{
public:
	Tile(int const x,
		int const y,
		int const width,
		int const height,
		sf::Texture const& tex);

	sf::Vector2i vec() const;
private:
	int x;
	int y;
	int width;
	int height;
};

#endif
