#ifndef GRID_H
#define GRID_H

#include <vector>
#include <memory>
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
	std::vector<std::shared_ptr<Tile>>& get_tiles();
	int get_offset_x() const;
	int get_offset_y() const;
private:
	int offset_x;
	int offset_y;
	int width;
	int height;
	std::vector<std::shared_ptr<Tile>> tiles;
};

#endif
