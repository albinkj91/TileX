#include <SFML/Graphics.hpp>

class Tile : public sf::Sprite
{
public:
	Tile(float const x,
		float const y,
		float const width,
		float const height,
		sf::Texture const& tex);

	sf::Vector2f vec() const;
private:
	float x;
	float y;
	float width;
	float height;
};
