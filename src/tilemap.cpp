#include "tilemap.hpp"

Tilemap::Tilemap() : vert(sf::PrimitiveType::Triangles, 3){
  initTilemap();  
}

void Tilemap::initTilemap(){
  if(texture.loadFromFile("../assets/tileset.png")){
    texture.setSmooth(false);
    texture.setRepeated(false);
  }else{
    throw std::runtime_error("Holy fucking gosh");
  }
  for(auto& dump : map){
    dump.fill(static_cast<int>(tiles::background));
  }
  for(int i = 0; i < width; i++){
    for(int j = 0; j < height; j++){
      if(j >= 37 && j <= 40 && i >= 13 && i <= 73){
        map[i][j] = static_cast<int>(tiles::ground);   
      }else{
        map[i][j] = static_cast<int>(tiles::background);
      }
    }
  }
}

void Tilemap::updateTilemap(){
  vert.clear();
  vert.setPrimitiveType(sf::PrimitiveType::Triangles);
  vert.resize(width * height * 6);
  for(int i = 0; i < width; i++){
    for(int j = 0; j < height; j++){      
      int index = map[i][j];
      int tu = index % (texture.getSize().x / size);
      int tv = index / (texture.getSize().x / size);

      sf::Vertex* triangles = &vert[(i + j * width) * 6];

      triangles[0].position = sf::Vector2f(i * size, j * size);
      triangles[1].position = sf::Vector2f((i + 1) * size, j * size);
      triangles[2].position = sf::Vector2f(i * size, (j + 1) * size);
      triangles[3].position = sf::Vector2f(i * size, (j + 1) * size);
      triangles[4].position = sf::Vector2f((i + 1) * size, j * size);
      triangles[5].position = sf::Vector2f((i + 1) * size, (j + 1) * size);

      triangles[0].texCoords = sf::Vector2f(tu * size, tv * size);
      triangles[1].texCoords = sf::Vector2f((tu + 1) * size, tv * size);
      triangles[2].texCoords = sf::Vector2f(tu * size, (tv + 1) * size);
      triangles[3].texCoords = sf::Vector2f(tu * size, (tv + 1) * size);
      triangles[4].texCoords = sf::Vector2f((tu + 1) * size, tv * size);
      triangles[5].texCoords = sf::Vector2f((tu + 1) * size, (tv + 1) * size);
    }
  }
}

Tilemap::~Tilemap(){}
