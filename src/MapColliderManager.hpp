#pragma once

#include <SFML/Graphics.hpp>

#include "entity.hpp"
#include "tilemap.hpp"

class MapCollider{
public:
  void initMapCollider();
  bool isCollided();

private:
  sf::FloatRect getEntityBounds;
  sf::FloatRect getTilemapBounds;
  
private:
  bool collided;
  Entity entity;
  Tilemap tilemap;  
};
