#include "tilemap.hpp"

Tilemap::Tilemap() : vert(sf::PrimitiveType::Triangles, 3){
  initTilemap();
}

void Tilemap::initTilemap(){
  tilemapTexture = new sf::Texture;
  tilemapTexture = &tm.loadFullTexture("../assets/tileset.png");
  for (int i = 0; i < mapWidth; ++i) {
    for (int j = 0; j < mapHeight; ++j) {
      if (j >= 40 && j <= 42 && i >= 10 && i <= 70) {
        map[i][j] = static_cast<int>(tiles::ground);
      } else {
        map[i][j] = static_cast<int>(tiles::background);
      }
    }
  }
}

sf::FloatRect Tilemap::getTilemapBounds(){
  return sf::FloatRect({0,0},{static_cast<float>(tileSize*mapWidth), static_cast<float>(tileSize*mapHeight)});
}

void Tilemap::setCollisionLayer(collisionLayer tilemapcl){
  clt = tilemapcl;  
}

void Tilemap::setCollisionMask(std::vector<collisionLayer>tilemapMask){
  tilemapCollisionMask = tilemapMask;
}

collisionLayer Tilemap::getTilemapCollisionLayer(){
  return clt;
}

std::vector<collisionLayer> Tilemap::getTilemapCollisionMask(){
  return tilemapCollisionMask;
}

int Tilemap::getTilemap(int x, int y) {
    if (x < 0 || y < 0 || x >= mapWidth || y >= mapHeight) return -1;
    return map[x][y];
}

void Tilemap::makeTile() {
  vert.clear();
  vert.setPrimitiveType(sf::PrimitiveType::Triangles);
  vert.resize(mapWidth * mapHeight * 6);
  for (int i = 0; i < mapWidth; ++i) {
    for (int j = 0; j < mapHeight; ++j) {
      int index = map[i][j];
      int tu = index % (tilemapTexture->getSize().x / tileSize);
      int tv = index / (tilemapTexture->getSize().x / tileSize);
      sf::Vertex *tri = &vert[(i + j * mapWidth) * 6];
      tri[0].position = sf::Vector2f(i * tileSize, j * tileSize);
      tri[1].position = sf::Vector2f((i + 1) * tileSize, j * tileSize);
      tri[2].position = sf::Vector2f(i * tileSize, (j + 1) * tileSize);
      tri[3].position = sf::Vector2f(i * tileSize, (j + 1) * tileSize);
      tri[4].position = sf::Vector2f((i + 1) * tileSize, j * tileSize);
      tri[5].position = sf::Vector2f((i + 1) * tileSize, (j + 1) * tileSize);

      tri[0].texCoords = sf::Vector2f(tu * tileSize, tv * tileSize);
      tri[1].texCoords = sf::Vector2f((tu + 1) * tileSize, tv * tileSize);
      tri[2].texCoords = sf::Vector2f(tu * tileSize, (tv + 1) * tileSize);
      tri[3].texCoords = sf::Vector2f(tu * tileSize, (tv + 1) * tileSize);
      tri[4].texCoords = sf::Vector2f((tu + 1) * tileSize, tv * tileSize);
      tri[5].texCoords = sf::Vector2f((tu + 1) * tileSize, (tv + 1) * tileSize);
    }
  }
}

void Tilemap::draw(sf::RenderTarget &target, sf::RenderStates states) const {
  states.transform *= Transform();
  states.texture = tilemapTexture;
  target.draw(vert, states);
}
