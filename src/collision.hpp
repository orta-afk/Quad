#pragma once

#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>

#include "tilemap.hpp"
#include "entity.hpp"
#include "collisionLayers.hpp"

class Collider {
public:
  Collider(Entity &e, Tilemap &t) : entity(e), tilemap(t) {}
  void initCollider();
  bool TilemapAndEntity();

private:
  Entity &entity;
  Tilemap &tilemap;
  bool isCollided;
  sf::FloatRect entityBounds;
  sf::FloatRect tilemapBounds;
  std::vector<collisionLayer> entityMask;
  std::vector<collisionLayer> tilemapMask;
  collisionLayer entityLayer;
  collisionLayer tilemapLayer;
};
