#include <SFML/Graphics.hpp>

class Tile : public sf::Sprite
{
public:
	Tile(float x, float y, float width, float height);

	sf::Vector2f vec() const;
private:
	float x;
	float y;
	float width;
	float height;
};
