#pragma once

#include "SFML/Graphics/Sprite.hpp"
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>

class Entity {
public:
  Entity();
  void initEntity();
  void updateEntity();
  void renderEntity(sf::RenderWindow& window);
  ~Entity();

private:
  sf::Vector2f positions;
  sf::Texture texture;
  sf::Sprite player;

private:
  void initEntityTexture();
};
