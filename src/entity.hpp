#pragma once

#include "SFML/Graphics/Sprite.hpp"
#include "SFML/System/Vector2.hpp"
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>

class Entity {
public:
  Entity();
  void initEntity();
  void updateEntity(float dt);
  void renderEntity(sf::RenderWindow& window);

private:
  int XIndex;
  int YIndex;
  const int speed = 100;
  const int tilesize = 16;
  sf::Sprite player;
  sf::Texture texture;
  sf::Vector2f velocity{0,0};
  sf::Vector2f positions{100,100};

private:
  void initTexture();
  void move();
};
