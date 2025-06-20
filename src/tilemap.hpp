#pragma once

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <array>
#include <vector>

enum class tilemapTiles : int {
  background,
  ground,
};

class Tilemap {
public:
  Tilemap();
  void initTilemap();
  void updateTilemap();
  void renderTilemap(sf::RenderWindow &window);
  ~Tilemap();

private:
  int XIndex = 0;
  int YIndex = 0;
  int tileSize = 16;
  static const int mapWidth = 80;
  static const int mapHight = 45;
  std::array<std::array<int, mapHight>, mapWidth> map;
  std::vector<sf::Sprite> tiles;
  sf::Sprite tile;
  sf::Texture texture;
};
