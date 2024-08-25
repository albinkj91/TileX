#include <SFML/Graphics.hpp>
#include <iostream>
#include <algorithm>
#include <cmath>
#include <memory>
#include <utility>
#include "Tile.h"
using namespace std;

#define TILE_WIDTH 64
#define TILE_WIDTH_HALF 32
#define TILE_HEIGHT 32
#define TILE_HEIGHT_HALF 16
#define GRID_WIDTH 15

int main()
{
    sf::RenderWindow window(sf::VideoMode(1200, 800), "Isometric projection");
	bool mouse_down{false};

	vector<string> images{"grass.png", "tree.png"};
	vector<sf::Texture> textures{};

	for_each(images.begin(), images.end(),
			[&textures](string const& s)
			{
				sf::Texture t{};
				if(!t.loadFromFile("assets/" + s))
					cerr << "Error loading image" << endl;
				textures.push_back(t);
			});


	constexpr float offsetX{1200.f/2.f - TILE_HEIGHT};
	constexpr float offsetY{800.f/2.f - (TILE_HEIGHT_HALF * GRID_WIDTH)};

	vector<Tile> tiles{};
	for(int i{}; i < GRID_WIDTH; ++i)
	{
		for(int j{}; j < GRID_WIDTH; ++j)
		{
			Tile t{offsetX + TILE_WIDTH_HALF * (j-i),
				offsetY + TILE_HEIGHT_HALF * (j+i),
				TILE_WIDTH, TILE_HEIGHT};

			t.setTexture(textures.at(0));
			t.setPosition(t.vec());
			tiles.push_back(move(t));
		}
	}

	Tile tree{0, 0,
			  TILE_WIDTH, TILE_HEIGHT};
	tree.setTexture(textures.at(1));
	tree.setPosition(tree.vec());

    while (window.isOpen())
    {
        window.clear();

		for_each(tiles.begin(), tiles.end(),
				[&window](Tile const& t)
				{
					window.draw(t);
				});

		sf::Vector2i mouse = sf::Mouse::getPosition(window);
		
		float tx{((mouse.x - offsetX) / TILE_WIDTH_HALF + (mouse.y - offsetY) / TILE_HEIGHT_HALF)/2};
		float ty{(mouse.y - offsetY) / TILE_HEIGHT_HALF - tx};
		tx = round(tx)-1;
		ty = round(ty);

		if(tx >= 0 && tx < GRID_WIDTH && ty >= 0 && ty < GRID_WIDTH)
		{
			int index{static_cast<int>((ty*GRID_WIDTH) + tx)};
			sf::Vector2f pos{tiles.at(index).vec()};
			tree.setPosition(pos.x, pos.y - 3*TILE_WIDTH_HALF + 7);
			window.draw(tree);

			if(sf::Mouse::isButtonPressed(sf::Mouse::Left) && !mouse_down)
			{
				Tile tree2{pos.x, pos.y,
					TILE_WIDTH, TILE_HEIGHT};
				tree2.setPosition(pos.x, pos.y - 3*TILE_WIDTH_HALF + 16);
				tree2.setTexture(textures.at(1));
				tiles.at(index) = move(tree2);
				mouse_down = true;
			}
			else if(!sf::Mouse::isButtonPressed(sf::Mouse::Left) &&	mouse_down)
			{
				mouse_down = false;
			}
		}

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
