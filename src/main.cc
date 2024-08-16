#include <SFML/Graphics.hpp>
#include <iostream>
#include "Tile.h"
using namespace std;

int main()
{
    sf::RenderWindow window(sf::VideoMode(800, 800), "Isometric projection");

	Tile t{100.f, 100.f, 100.f, 50.f};

	sf::Texture texture;
	if (!texture.loadFromFile("assets/grass.png"))
	{
		cerr << "Error loading image" << endl;
	}

	sf::Sprite sprite{};
	sprite.setTexture(texture);

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.clear();
        window.draw(sprite);
        window.display();
    }
    return 0;
}
