#include "collider.hpp"

Collider::Collider(){
  initCollider();
}

void Collider::initCollider(){}

void Collider::updateCollider(){
  isCollided();  
}

collisionLayer Collider::giveCollisionLayer(){
  
}

bool Collider::isCollided(){
  if(const std::optional col = entity.getEntityBounds().findIntersection(tilemap.getTilemapBounds())){
    collided = true;
  } else{
    collided = false;
  }
  return collided;
}
