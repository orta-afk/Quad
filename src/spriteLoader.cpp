#include "spriteLoader.hpp"

sf::Texture& TextureManger::loadTexture(std::filesystem::path path, bool srbg,
                                       unsigned int size, unsigned int XIndex,
                                       unsigned int YIndex) {
  std::string yum = path.string();
  if (!yum.empty()) {
    if (!texture.loadFromFile(
            yum, srbg,
            sf::IntRect({static_cast<int>(size * XIndex),
                         static_cast<int>(size * YIndex)},
                        {static_cast<int>(size), static_cast<int>(size)}))) {
      throw std::runtime_error("fucking hell");
    } else {
      texture.setRepeated(false);
      texture.setSmooth(true);
    }
  } else {
    throw std::runtime_error("grrr");
  }
  return texture;
}

sf::Texture& TextureManger::loadFullTexture(std::filesystem::path path){
  std::string pa = path.string();
  if(!pa.empty()){
    if(!texture.loadFromFile(pa)){
      throw std::runtime_error("goon");
    }else{
      texture.setRepeated(false);
      texture.setSmooth(true);
    }
  }else{
    throw std::runtime_error("waifu");
  }
  return texture;
}
