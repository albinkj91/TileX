#include <iostream>
#include "ImageLoader.h"

static std::unordered_map<std::string, sf::Texture> images{};

sf::Texture& ImageLoader::get(std::string const& image_path)
{
	if(images.find(image_path) == std::end(images))
	{
		sf::Texture texture{};
		if(!texture.loadFromFile("assets/" + image_path))
			std::cerr << "Error loading image: " << image_path << std::endl;
		images.emplace(make_pair(image_path, texture));
	}
	return images.at(image_path);
}
