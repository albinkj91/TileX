#include "Grid.h"
#include "Image_Loader.h"

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
			int x{offset_x + tile_width/2 * (j-i)};
			int y{offset_y + tile_height/2 * (j+i)};
			Tile t{x, y, Image_Loader::get("placeholder.png")};
			t.set_pos(x, y);

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

int Grid::get_offset_x() const
{
	return offset_x;
}

int Grid::get_offset_y() const
{
	return offset_y;
}
