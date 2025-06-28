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

enum class EntityCollisionLayer : int{
  sprite = 0,
  gun = 1,
};

class Entity : public sf::Drawable {
public:
  Entity();
  void initEntity();
  void updateEntity(float dt, bool collided);

public:
  void setMask();
  sf::FloatRect getEntityBounds();
  std::vector<EntityCollisionLayer> EntityMask;
  std::vector<EntityCollisionLayer> getMask();
  EntityCollisionLayer ecl;


private:
  void move();
  void gravity();
  void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
  
private:
  data d;
  texture tex;
  TextureManger tm;
  sf::Texture entityTexture;
  sf::Sprite entitySprite;
};
