#include "collider.hpp"

bool Collider::isCollided() {
  if (entity.getEntityBounds().findIntersection(tilemap.getTilemapBounds())) {
    return true;
  } 
  return false;
}
