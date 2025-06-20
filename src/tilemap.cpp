#include "tilemap.hpp"

Tilemap::Tilemap() : vert(sf::PrimitiveType::Triangles) { initTilemap(); }

void Tilemap::initTilemap() {
  if (texture.loadFromFile("../assets/tileset.png")) {
    texture.setSmooth(true);
    texture.setRepeated(false);
  } else {
    throw std::runtime_error("ong wtf");
  }
  for (int y = 0; y < mapHeight; ++y) {
    for (int x = 0; x < mapWidth; ++x) {
      if (y >= 35 && y <= 37 && x >= 13 && x <= 73)
        map[y][x] = static_cast<int>(tiles::ground);
      else
        map[y][x] = static_cast<int>(tiles::backgroundTile);
    }
  }
}

void Tilemap::updateTilemap() {
  vert.clear();
  vert.resize(mapWidth * mapHeight * 6);

  int texCols = texture.getSize().x / tileSize;  

  for (int y = 0; y < mapHeight; ++y) {
    for (int x = 0; x < mapWidth; ++x) {
      int index = map[y][x];
      int tu = index % texCols;
      int tv = index / texCols;

      sf::Vertex *tri = &vert[(x + y * mapWidth) * 6];

      float px = x * tileSize;
      float py = y * tileSize;

      tri[0].position = {px, py};
      tri[1].position = {px + tileSize, py};
      tri[2].position = {px, py + tileSize};
      tri[3].position = {px, py + tileSize};
      tri[4].position = {px + tileSize, py};
      tri[5].position = {px + tileSize, py + tileSize};

      tri[0].texCoords = {static_cast<float>(tu) * tileSize, static_cast<float>(tv) * tileSize};
      tri[1].texCoords = {(static_cast<float>(tu) + 1) * tileSize, static_cast<float>(tv) * tileSize};
      tri[2].texCoords = {static_cast<float>(tu) * tileSize, (static_cast<float>(tv) + 1) * tileSize};
      tri[3].texCoords = {static_cast<float>(tu) * tileSize, (static_cast<float>(tv) + 1) * tileSize};
      tri[4].texCoords = {(static_cast<float>(tu) + 1) * tileSize, static_cast<float>(tv) * tileSize};
      tri[5].texCoords = {(static_cast<float>(tu) + 1) * tileSize, (static_cast<float>(tv) + 1) * tileSize};
    }
  }
}

Tilemap::~Tilemap() {}
