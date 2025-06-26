#include "entity.hpp"
#include <iostream>

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

sf::FloatRect Entity::getEntityBounds(){
  sf::FloatRect entitybound = entitySprite.getGlobalBounds();
  return entitybound;
}

void Entity::resloveCollision(bool isCollided) {
  if (isCollided) {
    if (velocity.y > 0) {
      velocity.y = 0;
      position.y = std::floor(position.y / size) * size;
      std::cout << "hly cow";
    }
    onGround = true;
  } else {
    onGround = false;
  }
}

void Entity::updateEntity(float dt, bool collided){
  gravity();
  move();  
  position += velocity * dt;
  entitySprite.setPosition(sf::Vector2f(position));
  resloveCollision(collided);
}

void Entity::gravity(){
  if(!onGround){
    velocity.y += g;
    if(velocity.y > max_g){
      velocity.y = max_g;
    }
  }
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

