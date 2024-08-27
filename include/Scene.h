#ifndef SCENE_H
#define SCENE_H

#include <SFML/Graphics.hpp>
#include "Grid.h"

#define TILE_WIDTH 64
#define TILE_WIDTH_HALF 32
#define TILE_HEIGHT 32
#define TILE_HEIGHT_HALF 16
#define GRID_WIDTH 15

class Scene
{
public:
	Scene(unsigned const w_width, unsigned const w_height);
	void run();
private:
	sf::RenderWindow window;

	Grid initialize() const;
	void render(Grid & grid);
};

#endif
