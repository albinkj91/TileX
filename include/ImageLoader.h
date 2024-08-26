#ifndef IMAGELOADER_H
#define IMAGELOADER_H

#include <SFML/Graphics.hpp>
#include <unordered_map>
#include <string>
#include <memory>

class ImageLoader
{
public:
	static sf::Texture& get(std::string const& image_path);
};

#endif
