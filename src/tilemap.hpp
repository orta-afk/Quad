#pragma once

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <array>

#include "spriteLoader.hpp"
#include "collisionLayers.hpp"

enum class tiles : int{
  ground = 0,
  background = 2,
};

class Tilemap : public sf::Drawable, public sf::Transform {
public:
  Tilemap();
  void initTilemap();
  void makeTile();
  sf::FloatRect getTilemapBounds();
  void draw(sf::RenderTarget& target, sf::RenderStates states) const override;

public:
  int getTilemap(int x, int y);
  void setCollisionLayer(collisionLayer tilemapcl);
  void setCollisionMask(std::vector<collisionLayer> tilemapMask);
  collisionLayer getTilemapCollisionLayer();
  std::vector<collisionLayer> getTilemapCollisionMask();

private:
  static const int mapWidth = 80;
  static const int mapHeight = 45;
  const int tileSize = 16;
  std::array<std::array<int, mapHeight>, mapWidth> map;
  std::vector<collisionLayer> tilemapCollisionMask;
  sf::VertexArray vert;
  sf::Texture* tilemapTexture;

private:
  collisionLayer clt;
  TextureManger tm;
};
