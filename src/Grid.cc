#include "Grid.h"
#include "ImageLoader.h"

Grid::Grid(int const offset_x,
		int const offset_y,
		int const width,
		int const height)
	:offset_x{offset_x},
	offset_y{offset_y},
	width{width},
	height{height},
	tiles{}
{ }

void Grid::create(int const tile_width, int const tile_height)
{
	for(int i{}; i < height; ++i)
	{
		for(int j{}; j < width; ++j)
		{
			Tile t{offset_x + tile_width/2 * (j-i),
				offset_y + tile_height/2 * (j+i),
				tile_width, tile_height,
				ImageLoader::get("placeholder.png")};

			t.setPosition(static_cast<sf::Vector2f>(t.vec()));
			tiles.push_back(t);
		}
	}
}

Tile& Grid::at(int const x, int const y)
{
	return tiles.at(y * width + x);
}

std::vector<Tile>& Grid::get_tiles()
{
	return tiles;
}
