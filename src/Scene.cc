#include "Scene.h"
#include "Grid.h"
#include "Large_Tile.h"
#include "Image_Loader.h"
#include <cmath>
#include <iostream>
#include <memory>

Scene::Scene(unsigned const w_width, unsigned const w_height)
	:window{sf::VideoMode{w_width, w_height}, "TileX"}
{ }

Grid Scene::initialize() const
{
	int offset_x{static_cast<int>(window.getSize().x)/2 - TILE_HEIGHT};
	int offset_y{static_cast<int>(window.getSize().y)/2 - (TILE_HEIGHT_HALF * GRID_WIDTH)};

	Grid grid{offset_x, offset_y, GRID_WIDTH, GRID_WIDTH};
	grid.create(TILE_WIDTH, TILE_HEIGHT);
	return grid;
}

void Scene::render(Grid & grid)
{
	this->window.clear(sf::Color{135, 206, 235, 255});
	std::for_each(grid.get_tiles().begin(), grid.get_tiles().end(),
			[this](std::shared_ptr<Tile> const& t)
			{
				this->window.draw(t->get_sprite());
			});
}

void Scene::run()
{
	int keyboard_state{1};

	Grid grid{initialize()};
	std::vector<std::shared_ptr<Tile>> types{};

	types.push_back(std::make_shared<Tile>(Tile{0, 0, Image_Loader::get("placeholder.png")}));
	types.push_back(std::make_shared<Tile>(Tile{0, 0, Image_Loader::get("grass.png")}));
	types.push_back(std::make_shared<Tile>(Tile{0, 0, Image_Loader::get("grass2.png")}));
	types.push_back(std::make_shared<Tile>(Tile{0, 0, Image_Loader::get("water.png")}));
	types.push_back(std::make_shared<Large_Tile>(Large_Tile{0, 0, Image_Loader::get("flower.png")}));
	types.push_back(std::make_shared<Large_Tile>(Large_Tile{0, 0, Image_Loader::get("tree.png")}));

	std::shared_ptr<Tile> current{types.at(keyboard_state)};

	while (this->window.isOpen())
	{
		render(grid);

		sf::Vector2i mouse = sf::Mouse::getPosition(this->window);
		
		float tx{((mouse.x - static_cast<float>(grid.get_offset_x())) / TILE_WIDTH_HALF + (mouse.y - static_cast<float>(grid.get_offset_y())) / TILE_HEIGHT_HALF)/2};
		float ty{(mouse.y - static_cast<float>(grid.get_offset_y())) / TILE_HEIGHT_HALF - tx};
		tx = round(tx)-1;
		ty = round(ty);

		if(tx >= 0 && tx < GRID_WIDTH && ty >= 0 && ty < GRID_WIDTH)
		{
			current = types.at(keyboard_state);
			sf::Vector2i pos{grid.at(tx, ty).get_pos()};
			current->set_pos(pos.x, pos.y - 7);
			this->window.draw(current->get_sprite());

			if(sf::Mouse::isButtonPressed(sf::Mouse::Left))
			{
				current->set_pos(pos.x, pos.y);
				grid.at(tx, ty) = *current;
			}
			else if(sf::Mouse::isButtonPressed(sf::Mouse::Right))
			{
				grid.at(tx, ty) = *types.at(0);
				grid.at(tx, ty).set_pos(pos.x, pos.y);
			}
		}

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num1))
			keyboard_state = 1;
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num2))
			keyboard_state = 2;
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num3))
			keyboard_state = 3;
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num4))
			keyboard_state = 4;
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num5))
			keyboard_state = 5;

        sf::Event event;
        while (this->window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                this->window.close();
        }
      this->window.display();
    }
}
