#include "Scene.h"
#include "Grid.h"
#include "ImageLoader.h"
#include <cmath>

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
			[this](Tile const& t)
			{
				this->window.draw(t);
			});
}

void Scene::run()
{
	int keyboard_state{1};

	Grid grid{initialize()};
	std::vector<Tile> types{};

	types.push_back(Tile{0, 0,
			  TILE_WIDTH, TILE_HEIGHT,
			  ImageLoader::get("placeholder.png")});
	types.push_back(Tile{0, 0,
			  TILE_WIDTH, TILE_HEIGHT,
			  ImageLoader::get("grass.png")});
	types.push_back(Tile{0, 0,
			  TILE_WIDTH, TILE_HEIGHT,
			  ImageLoader::get("grass2.png")});
	types.push_back(Tile{0, 0,
			  TILE_WIDTH, TILE_HEIGHT,
			  ImageLoader::get("water.png")});
	types.push_back(Tile{0, 0,
			  TILE_WIDTH, TILE_HEIGHT,
			  ImageLoader::get("tree.png")});

	while (this->window.isOpen())
	{
		render(grid);
		// ************************ Draw grid **************************
		// ********************************************************



		// **************** Input handling ************************
		sf::Vector2i mouse = sf::Mouse::getPosition(this->window);
		
		float tx{((mouse.x - static_cast<float>(grid.get_offset_x())) / TILE_WIDTH_HALF + (mouse.y - static_cast<float>(grid.get_offset_y())) / TILE_HEIGHT_HALF)/2};
		float ty{(mouse.y - static_cast<float>(grid.get_offset_y())) / TILE_HEIGHT_HALF - tx};
		tx = round(tx)-1;
		ty = round(ty);

		Tile current{types.at(keyboard_state)};

		if(tx >= 0 && tx < GRID_WIDTH && ty >= 0 && ty < GRID_WIDTH)
		{
			sf::Vector2i pos{grid.at(tx, ty).vec()};
			current.setPosition(pos.x, pos.y - 7);
			this->window.draw(current);

			if(sf::Mouse::isButtonPressed(sf::Mouse::Left))
			{
				current.setPosition(pos.x, pos.y);
				grid.at(tx, ty) = current;
			}
			//else if(sf::Mouse::isButtonPressed(sf::Mouse::Right))
			//{
			//	keyboard_state = 0;
			//}
		}

		//****************************************************

        sf::Event event;
        while (this->window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                this->window.close();
        }
        this->window.display();
    }
}