#include "entity.hpp"

Entity::Entity() : player(texture){
  initEntity();
}

void Entity::initEntity(){
  initEntityTexture();
}

void Entity::updateEntity(){
  if(sf::Keyboard::isKeyPressed(sf::Keyboard::Scancode::A)){
    player.setPosition({positions.x + 10, positions.y + 10});
  }  
}

void Entity::renderEntity(sf::RenderWindow& window){
  window.draw(player);
}

void Entity::initEntityTexture(){ 
  if(texture.loadFromFile("../assets/tileset.png")){
    player.setTexture(texture);
    player.setTextureRect(sf::IntRect({1*16, 0*16}, {16,16}));
  }
  texture.setSmooth(true);
  texture.setRepeated(false);
}

Entity::~Entity(){

}
