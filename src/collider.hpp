#pragma once

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>

#include "entity.hpp"
#include "tilemap.hpp"


enum class collisionLayer : int{
  entity = 0,
  backgroundTile = 1,
  groundTile = 2,
};

class Collider {
public:
  Collider();
  void initCollider();
  void updateCollider();
  collisionLayer giveCollisionLayer();
  bool isCollided();
  
private:
  bool collided;
  collisionLayer cl;
  Entity entity;
  Tilemap tilemap;
};
