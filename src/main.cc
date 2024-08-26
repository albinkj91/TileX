#include <SFML/Graphics.hpp>
#include <iostream>
#include <algorithm>
#include <cmath>
#include <memory>
#include <utility>
#include "Tile.h"
#include "ImageLoader.h"
#include "Grid.h"

using namespace std;

#define WINDOW_WIDTH 1200
#define WINDOW_HEIGHT 800
#define TILE_WIDTH 64
#define TILE_WIDTH_HALF 32
#define TILE_HEIGHT 32
#define TILE_HEIGHT_HALF 16
#define GRID_WIDTH 15

int main()
{
    sf::RenderWindow window(sf::VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT), "Isometric projection");

	constexpr int offset_x{WINDOW_WIDTH/2 - TILE_HEIGHT};
	constexpr int offset_y{WINDOW_HEIGHT/2 - (TILE_HEIGHT_HALF * GRID_WIDTH)};

	Grid grid{offset_x, offset_y, GRID_WIDTH, GRID_WIDTH};
	grid.create(TILE_WIDTH, TILE_HEIGHT);

	Tile water{0, 0,
			  TILE_WIDTH, TILE_HEIGHT,
			  ImageLoader::get("water.png")};
	water.setPosition(water.vec().x, water.vec().y);

    while (window.isOpen())
    {
		// ************************ Draw grid **************************
        window.clear(sf::Color{135, 206, 235, 255});

		for_each(grid.get_tiles().begin(), grid.get_tiles().end(),
				[&window](Tile const& t)
				{
					window.draw(t);
				});
		// ********************************************************



		// **************** Input handling ************************
		sf::Vector2i mouse = sf::Mouse::getPosition(window);
		
		float tx{((mouse.x - static_cast<float>(offset_x)) / TILE_WIDTH_HALF + (mouse.y - static_cast<float>(offset_y)) / TILE_HEIGHT_HALF)/2};
		float ty{(mouse.y - static_cast<float>(offset_y)) / TILE_HEIGHT_HALF - tx};
		tx = round(tx)-1;
		ty = round(ty);

		if(tx >= 0 && tx < GRID_WIDTH && ty >= 0 && ty < GRID_WIDTH)
		{
			sf::Vector2i pos{grid.at(tx, ty).vec()};
			water.setPosition(pos.x, pos.y - 7);
			window.draw(water);

			if(sf::Mouse::isButtonPressed(sf::Mouse::Left))
			{
				Tile tree2{pos.x, pos.y,
					TILE_WIDTH, TILE_HEIGHT,
					ImageLoader::get("water.png")};
				tree2.setPosition(pos.x, pos.y);
				grid.at(tx, ty) = tree2;
			}
			else if(sf::Mouse::isButtonPressed(sf::Mouse::Right))
			{
				Tile t{pos.x, pos.y,
					TILE_WIDTH, TILE_HEIGHT,
					ImageLoader::get("placeholder.png")};

				t.setPosition(t.vec().x, t.vec().y);
				grid.at(tx, ty) = t;
			}
		}

		//****************************************************

        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }
        window.display();
    }
    return 0;
}
