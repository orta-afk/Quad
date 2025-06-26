#pragma once

#include <SFML/Graphics.hpp>

#include "entity.hpp"
#include "tilemap.hpp"

class Collider {
public:
  bool isCollided();

private:
  bool collided;
  Entity entity;
  Tilemap tilemap;
};
