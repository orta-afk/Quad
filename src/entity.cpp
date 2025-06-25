#include "entity.hpp"

Entity::Entity() : entitySprite(entityTexture){
  initEntity();
}


void Entity::initEntity(){
  size = 16;
  XIndex = 1;
  YIndex = 0;
  sf::Texture* t;
  t = &tm.loadTexture("../assets/tileset.png", false, size, XIndex , YIndex);
  entitySprite.setTexture(*t);
  entitySprite.setTextureRect(sf::IntRect({static_cast<int>(size) * static_cast<int>(XIndex), static_cast<int>(size) * static_cast<int>(YIndex)}, {static_cast<int>(size), static_cast<int>(size)}));
  entitySprite.setPosition(sf::Vector2f(position));
  entityTexture = *t;
}

void Entity::updateEntity(float dt){
  move();  
  position += velocity * dt;
  entitySprite.setPosition(sf::Vector2f(position));
}

void Entity::move(){
  if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key::A)){
    velocity.x = -speed;
  } else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key::D)){
    velocity.x = speed;
  }
  else{
    velocity.x = 0;
  }
  if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key::W)){
    velocity.y = -speed;
  }
}

void Entity::draw(sf::RenderTarget& target, sf::RenderStates states) const {
  target.draw(entitySprite);
}

