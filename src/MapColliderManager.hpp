#pragma once

#include <SFML/Graphics.hpp>
#include <algorithm>

#include "entity.hpp"
#include "tilemap.hpp"

class MapCollider{
public:
  bool EntityWithTilemapCollision();

private:
  sf::FloatRect getEntityBounds;
  sf::FloatRect getTilemapBounds;
  
private:
  bool collided;
  Entity entity;
  Tilemap tilemap;  
};
