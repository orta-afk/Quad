#pragma once

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <array>

#include "spriteLoader.hpp"

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

private:
  void draw(sf::RenderTarget& target, sf::RenderStates states) const override;

private:
  static const int mapWidth = 40;
  static const int mapHeight = 30;
  const int tileSize = 16;
  std::array<std::array<int, mapHeight>, mapWidth> map;
  sf::VertexArray vert;
  sf::Texture* tilemapTexture;

private:
  TextureManger tm;
};
