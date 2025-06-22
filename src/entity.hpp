#pragma once

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>

class Entity {
public:
  Entity();
  void initEntity();
  void updateEntity(float dt);
  void renderEntity(sf::RenderWindow &window);

private:
  int XIndex = 0;
  int YIndex = 0;
  const int speed = 100;
  const int tilesize = 16;
  sf::Sprite player;
  sf::Texture texture;

private:
  int g = 100;
  const int max_gravity = 400;
  sf::Vector2f velocity{0, 0};
  sf::Vector2f positions{100, 100};

private:
  void initTexture();
  void move();
  void gravity(float dt);
};
