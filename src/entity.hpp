#pragma once

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <vector>
#include <cmath>

#include "spriteLoader.hpp"
#include "collisionLayers.hpp"

struct data {
  int g = 700;           
  int max_g = 1400;       
  int speed = 340;        
  int jumpHeight = 300;
  bool canJump;
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
  void jump(float dt);
  void gravity(float dt);
  void resloveCollision(bool collided);
  void draw(sf::RenderTarget& target, sf::RenderStates states) const override;

public:
  sf::Vector2f getPosition();
  void setEntityCollisionLayer(collisionLayer entitycl);
  void setEntityCollisionMask(std::vector<collisionLayer> entityMask);
  collisionLayer getEntityCollisionLayer();
  std::vector<collisionLayer> getEntityCollisionMask();
  
private:
  data d;
  texture tex;
  TextureManger tm;
  collisionLayer cl;
  sf::Texture entityTexture;
  sf::Sprite entitySprite;
  std::vector<collisionLayer> entityCollisionMask;
};
