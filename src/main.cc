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


	float offsetX{1200.f/2.f - TILE_HEIGHT};
	float offsetY{800.f/2.f - ((TILE_HEIGHT/2.f) * GRID_WIDTH)};
	Tile tree{offsetX,
			  offsetY + TILE_HEIGHT/2.f-7,
			  TILE_WIDTH, TILE_HEIGHT};

	vector<Tile> tiles{};
	for(int i{}; i < GRID_WIDTH; ++i)
	{
		for(int j{}; j < GRID_WIDTH; ++j)
		{
			Tile t{offsetX + TILE_WIDTH/2.f*j,
				offsetY + TILE_HEIGHT/2.f*j,
				TILE_WIDTH, TILE_HEIGHT};

			t.setTexture(textures.at(0));
			t.setPosition(t.vec());
			tiles.push_back(t);
		}
		offsetX -= TILE_WIDTH/2.f;
		offsetY += TILE_HEIGHT/2.f;
	}

	tree.setTexture(textures.at(1));
	tree.setPosition(tree.vec());

	offsetX = 1200.f/2.f - TILE_HEIGHT;
	offsetY = 800.f/2.f - ((TILE_HEIGHT/2.f) * GRID_WIDTH);

    while (window.isOpen())
    {
		sf::Vector2i mouse = sf::Mouse::getPosition(window);

		sf::CircleShape circ(10.f);
		circ.setFillColor(sf::Color(255, 50, 50));
		float temp_x{(mouse.x - TILE_WIDTH/2.f - offsetX) / (TILE_WIDTH/2.f)};
		float temp_y{(mouse.y - TILE_HEIGHT/2.f - offsetY) / (TILE_HEIGHT/2.f)};
		int x{(int)temp_x};
		int y{(int)temp_y};
		
		cout << "x: " << x << "\ty: " << y << endl;

		if(x >= 0 && x < 15 && y >= 0 && y < 15)
		{
			Tile test{tiles.at(x)}; //TODO
			circ.setPosition(test.vec().x, test.vec().y);
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
