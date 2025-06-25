#pragma once

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>

#include "spriteLoader.hpp"

class Entity : public sf::Drawable, public sf::Transform{
public:
  Entity();
  void initEntity();
  void updateEntity(float dt);

private:
  virtual void move();
  void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
  
private:
  int speed = 100;
  sf::Vector2f velocity;
  sf::Vector2f position;
  
private:
  unsigned int XIndex;
  unsigned int YIndex;
  unsigned int size;
  sf::Texture entityTexture;
  sf::Sprite entitySprite;

private:
  TextureManger tm;
};
