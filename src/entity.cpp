#include "entity.hpp"

Entity::Entity() : player(texture) { initEntity(); }

void Entity::initEntity() { initTexture(); }

void Entity::gravity(float dt){
  velocity.y += g;
  if(velocity.y >= max_gravity){
    velocity.y = max_gravity;
  }
}

void Entity::move() {
  velocity = {0, 0};
  if (sf::Keyboard::isKeyPressed(sf::Keyboard::Scancode::A)) {
    velocity.x = -speed;
  } else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Scancode::D)) {
    velocity.x = speed;
  } else {
    velocity.x = 0;
  }
}

void Entity::updateEntity(float dt) {
  player.setPosition(sf::Vector2f(positions));
  positions += velocity * dt;
  if (velocity.length() > 0) {
    velocity.x = velocity.normalized().x * speed;
  }
  move();
  gravity(dt);
}

void Entity::renderEntity(sf::RenderWindow &window) { window.draw(player); }

void Entity::initTexture() {
  XIndex = 1;
  YIndex = 0;
  if (texture.loadFromFile("../assets/tileset.png", false,
                           sf::IntRect({tilesize * XIndex, tilesize * YIndex},
                                       {tilesize, tilesize}))) {
    player.setTexture(texture);
    player.setTextureRect(sf::IntRect({tilesize * XIndex, tilesize * YIndex},
                                      {tilesize, tilesize}));
    texture.setSmooth(true);
    texture.setRepeated(false);
  } else {
    throw std::runtime_error("fucking hell");
  }
}
