#pragma once

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <filesystem>

class TextureManger {
public:
  sf::Texture& loadTexture(std::filesystem::path path, bool srbg,
                          unsigned int size, unsigned int XIndex,
                          unsigned int YIndex);

  sf::Texture& loadFullTexture(std::filesystem::path path);
private:
  sf::Texture texture;
};
