#include "entity.hpp"
#include "SFML/System/Vector2.hpp"
#include "SFML/Window/Cursor.hpp"

Entity::Entity() : player(texture){
  initEntity();
}

void Entity::initEntity(){
  initTexture();
}

void Entity::move(){
  velocity = {0,0};
  if(sf::Keyboard::isKeyPressed(sf::Keyboard::Scancode::W)){
    velocity.y = -speed;
  } else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Scancode::S)){
    velocity.y = speed;
  }
  if(sf::Keyboard::isKeyPressed(sf::Keyboard::Scancode::A)){
    velocity.x = -speed;
  } else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Scancode::D)){
    velocity.x = speed;
  }
  else{
    velocity.x = 0;
  }
}

void Entity::updateEntity(float dt){
  player.setPosition(sf::Vector2f(positions));
  positions += velocity * dt;
  move();
}

void Entity::renderEntity(sf::RenderWindow& window){
  window.draw(player);
}

void Entity::initTexture(){ 
  XIndex = 1;
  YIndex = 0;
  if(texture.loadFromFile("../assets/tileset.png", false, sf::IntRect({tilesize*XIndex,tilesize*YIndex},{tilesize,tilesize}))){
    player.setTexture(texture);
    player.setTextureRect(sf::IntRect({tilesize*XIndex, tilesize*YIndex}, {tilesize, tilesize}));
    texture.setSmooth(true);
    texture.setRepeated(false);
  }else{
    throw std::runtime_error("fucking hell");
  }
}
