#include "MapColliderManager.hpp"

void MapCollider::initMapCollider(){
  getEntityBounds = entity.getEntityBounds();
  getTilemapBounds = tilemap.getTilemapBounds();
}

bool MapCollider::isCollided(){
}
