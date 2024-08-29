#ifndef TILE_H
#define TILE_H

#include <SFML/Graphics.hpp>

class Tile
{
public:
	Tile(int const x, int const y, sf::Texture const& tex);
	virtual ~Tile() = default;

	virtual void set_pos(int const x, int const y);
	sf::Vector2i get_pos() const;
	sf::Sprite get_sprite() const;
protected:
	sf::Sprite sprite;
private:
	sf::Vector2i pos;
};

#endif
