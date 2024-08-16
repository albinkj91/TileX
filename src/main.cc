#include <SFML/Graphics.hpp>
#include <iostream>
#include <algorithm>
#include "Tile.h"
using namespace std;

int main()
{
    sf::RenderWindow window(sf::VideoMode(800, 800), "Isometric projection");

	sf::Texture texture;
	if (!texture.loadFromFile("assets/grass.png"))
	{
		cerr << "Error loading image" << endl;
	}

	float offsetX{800.f/2.f - 32.f};
	float offsetY{0};

	vector<Tile> tiles{};
	for(int i{}; i < 5; ++i)
	{
		for(int j{}; j < 5; ++j)
		{
			Tile t{offsetX + 64.f/2*j, offsetY + 32.f/2*j, 64.f, 32.f};
			t.setTexture(texture);
			t.setPosition(t.vec());
			tiles.push_back(t);
		}
		offsetX -= 32.f;
		offsetY += 16.f;
	}

    while (window.isOpen())
    {
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
        window.display();
    }
    return 0;
}
