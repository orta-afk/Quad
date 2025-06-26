#pragma once

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <cmath>

#include "spriteLoader.hpp"

struct data {
  int g = 120;
  int max_g = 300;
  int speed = 100;
  bool onGround = false;
  sf::Vector2f velocity;
  sf::Vector2f position;
};

struct texture {
  unsigned int XIndex = 1;
  unsigned int YIndex = 0;
  unsigned int size = 16;
};

class Entity : public sf::Drawable {
public:
  Entity();
  void initEntity();
  void updateEntity(float dt, bool collided);
  sf::FloatRect getEntityBounds();

private:
  void move();
  void gravity();
  virtual void resloveCollision(bool isCollided); 
  void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
  
private:
  data d;
  texture tex;
  TextureManger tm;
  sf::Texture entityTexture;
  sf::Sprite entitySprite;
};
