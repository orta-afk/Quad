#include "collider.hpp"
#include <iostream>

bool Collider::isCollided() {
  if (entity.getEntityBounds().findIntersection(tilemap.getTilemapBounds())) {
    std::cout << "from collider " << collided << std::endl;
    return true;
  } 
  return false;
}
