#pragma once

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <array>

#include "spriteLoader.hpp"

enum class tiles : int{
  ground = 0,
  background = 2,
};


enum class tileLayer : int{
  background = 0,
  ground = 1,
};

class Tilemap : public sf::Drawable, public sf::Transform {
public:
  Tilemap();
  void initTilemap();
  void makeTile();

public:
  sf::FloatRect getTilemapBounds();
  void setMask();
  tileLayer getMask(int x, int y);

private:
  void draw(sf::RenderTarget& target, sf::RenderStates states) const override;

private:
  static const int mapWidth = 40;
  static const int mapHeight = 30;
  const int tileSize = 16;
  std::array<std::array<int, mapHeight>, mapWidth> map;
  std::array<std::array<tileLayer, mapHeight>, mapWidth> tileMasks;
  sf::VertexArray vert;
  sf::Texture* tilemapTexture;

private:
  TextureManger tm;
  tileLayer tl;
};
