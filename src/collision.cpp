#include "collision.hpp"
#include "SFML/System/Vector2.hpp"
#include "collisionLayers.hpp"

void Collider::initCollider() {
  entity.setEntityCollisionLayer(collisionLayer::entity);
  tilemap.setCollisionLayer(collisionLayer::tilemap);
  entity.setEntityCollisionMask({collisionLayer::tilemap});
  tilemap.setCollisionMask({collisionLayer::entity});

  entityLayer = entity.getEntityCollisionLayer();
  tilemapLayer = tilemap.getTilemapCollisionLayer();

  entityMask = entity.getEntityCollisionMask();
  tilemapMask = tilemap.getTilemapCollisionMask();  

  entityBounds = entity.getEntityBounds();
  tilemapBounds = tilemap.getTilemapBounds();
}

bool Collider::TilemapAndEntity(){
  entityBounds = entity.getEntityBounds();
  tilemapBounds = tilemap.getTilemapBounds();
  if(!entity.getEntityBounds().findIntersection(tilemapBounds)){
    isCollided = false;
  };
  for(auto& mask : entityMask){
    if(mask == tilemapLayer){
      sf::Vector2f entityPosition = entity.getPosition();
      int tileX = static_cast<int>((entityPosition.x + entityBounds.size.x/2)/16);
      int tileY = static_cast<int>((entityPosition.y + entityBounds.size.y)/16);

      int tileType = tilemap.getTilemap(tileX, tileY);
      if(entity.getEntityBounds().findIntersection(tilemapBounds)){
        if (tileType == static_cast<int>(tiles::background)) {
          isCollided = false;
        }
        if (tileType == static_cast<int>(tiles::ground)) {
          isCollided = true;
          return true;
        }
      }
    }
  }
  return isCollided;
}
