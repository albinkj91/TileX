#ifndef IMAGE_LOADER_H
#define IMAGE_LOADER_H

#include <SFML/Graphics.hpp>
#include <string>

class Image_Loader
{
public:
	static sf::Texture& get(std::string const& image_path);
};

#endif
