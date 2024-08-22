#include <SFML/Graphics.hpp>
#include <iostream>
#include <algorithm>
#include <cmath>
#include "Tile.h"
using namespace std;

#define TILE_WIDTH 64.f
#define TILE_HEIGHT 32.f
#define GRID_WIDTH 15

int main()
{
    sf::RenderWindow window(sf::VideoMode(1200, 800), "Isometric projection");

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
	constexpr float offsetY{800.f/2.f - ((TILE_HEIGHT/2.f) * GRID_WIDTH)};
	Tile tree{offsetX,
			  offsetY + TILE_HEIGHT/2.f-7,
			  TILE_WIDTH, TILE_HEIGHT};

	vector<Tile> tiles{};
	for(int i{}; i < GRID_WIDTH; ++i)
	{
		for(int j{}; j < GRID_WIDTH; ++j)
		{
			Tile t{offsetX + TILE_WIDTH/2.f * (j-i),
				offsetY + TILE_HEIGHT/2.f * (j+i),
				TILE_WIDTH, TILE_HEIGHT};

			t.setTexture(textures.at(0));
			t.setPosition(t.vec());
			tiles.push_back(t);
		}
	}

	tree.setTexture(textures.at(1));
	tree.setPosition(tree.vec());

    while (window.isOpen())
    {
		sf::Vector2i mouse = sf::Mouse::getPosition(window);

		sf::CircleShape circ(10.f);
		circ.setFillColor(sf::Color(255, 50, 50));
		
		float tx{floor((mouse.x - offsetX) / TILE_WIDTH + (mouse.y - offsetY) / TILE_HEIGHT)};
		float ty{floor((mouse.y - offsetY) * 2.f/TILE_HEIGHT - tx)};
		if(tx >= 0 && tx < 15 && ty >= 0 && ty < 15)
		{
			sf::Vector2f pos{tiles.at((ty*GRID_WIDTH) + tx).getPosition()};
			circ.setPosition(pos.x + TILE_WIDTH/2.f-circ.getRadius(), pos.y);
		}

        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.clear();
		for_each(tiles.begin(), tiles.end(),
				[&window](Tile const& t)
				{
					window.draw(t);
				});
		window.draw(tree);
		window.draw(circ);
        window.display();
    }
    return 0;
}
