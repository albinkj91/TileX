#include <SFML/Graphics.hpp>
#include "Tile.h"

class Large_Tile : public Tile
{
public:
	Large_Tile(int const x, int const y, sf::Texture const& tex);
	~Large_Tile() = default;

	void set_pos(int const x, int const y) override;
private:
};
