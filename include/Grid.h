#ifndef GRID_H
#define GRID_H

#include <vector>
#include "Tile.h"

class Grid
{
public:
	Grid(int const offset_x,
		int const offset_y,
		int const width,
		int const height);

	void create(int const tile_width, int const tile_height);
	Tile& at(int const x, int const y);
	std::vector<Tile>& get_tiles();
private:
	int offset_x;
	int offset_y;
	int width;
	int height;
	std::vector<Tile> tiles;
};

#endif
