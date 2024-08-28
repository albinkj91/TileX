#ifndef IMAGE_LOADER_H
#define IMAGE_LOADER_H

#include <SFML/Graphics.hpp>
#include <unordered_map>
#include <string>
#include <memory>

class Image_Loader
{
public:
	static sf::Texture& get(std::string const& image_path);
};

#endif
