#include "tilemap.hpp"

Tilemap::Tilemap() : tile(texture) { initTilemap(); }

void Tilemap::initTilemap() {
  if (texture.loadFromFile("../assets/tileset.png", false,
                           sf::IntRect({XIndex * tileSize, YIndex * tileSize}, {tileSize, tileSize}))) {
    texture.setSmooth(true);
    texture.setRepeated(false);
  }
}

void Tilemap::updateTilemap() {
  int row = texture.getSize().x / tileSize;
  for (int i = 0; i < mapWidth; i++) {
    for (int j = 0; j < mapHight; j++) {
      tilemapTiles id;
      if (j >= 35 && j <= 37 && i >= 13 && i <= 67){   
        id = tilemapTiles::ground;
      } else{
        id = tilemapTiles::background;
      }
      map[i][j] = static_cast<int>(id);
      switch(id){
        case tilemapTiles::background:
          XIndex = 2;
          YIndex = 0;
          break;
        case tilemapTiles::ground:
          XIndex = 0;
          YIndex = 0;
          break;
      }
      tile.setTexture(texture);
      tile.setPosition(sf::Vector2f(static_cast<int>(i * tileSize), static_cast<int>(j * tileSize)));
      tile.setTextureRect(sf::IntRect({XIndex * tileSize, YIndex * tileSize},
                                    {tileSize, tileSize}));
      tiles.push_back(tile);
    }
  }
}

void Tilemap::renderTilemap(sf::RenderWindow &window) {
  for (auto &yum : tiles) {
    window.draw(yum);
  }
}

Tilemap::~Tilemap() {}
