#include "entity.hpp"

Entity::Entity() : entitySprite(entityTexture){
  initEntity();
}

void Entity::initEntity() {
  tex.size = 16;
  tex.XIndex = 1;
  tex.YIndex = 0;

  sf::Texture* loadedTex = &tm.loadTexture("../assets/tileset.png", false, tex.size, tex.XIndex, tex.YIndex);
  entityTexture = *loadedTex;
  entitySprite.setTexture(entityTexture);
  entitySprite.setTextureRect(sf::IntRect(
    {static_cast<int>(tex.size) * static_cast<int>(tex.XIndex),
     static_cast<int>(tex.size) * static_cast<int>(tex.YIndex)},
    {static_cast<int>(tex.size), static_cast<int>(tex.size)}
  ));
  entitySprite.setPosition(d.position);
}

sf::FloatRect Entity::getEntityBounds() {
  return entitySprite.getGlobalBounds();
}


void Entity::resloveCollision(bool collided){
  if(collided){
  if (d.velocity.y > 0) {
      d.velocity.y = 0;
      d.position.y = std::floor(d.position.y / tex.size) * tex.size;
    }
    d.onGround = true;
  } else {
    d.onGround = false;
  }
}

void Entity::updateEntity(float dt, bool collided) {
  resloveCollision(collided);
  gravity();
  move();
  d.position += d.velocity * dt;
  entitySprite.setPosition(d.position);
}

void Entity::setEntityCollisionLayer(collisionLayer entitycl){
  cl = entitycl; 
}

void Entity::setEntityCollisionMask(std::vector<collisionLayer> entityMask){
  entityCollisionMask = entityMask;
}

collisionLayer Entity::getEntityCollisionLayer(){
  return cl;
}

std::vector<collisionLayer> Entity::getEntityCollisionMask(){
  return entityCollisionMask;
}

sf::Vector2f Entity::getPosition(){
  return d.position;
}

void Entity::gravity() {
  if (!d.onGround) {
    d.velocity.y += d.g;
    if (d.velocity.y > d.max_g) {
      d.velocity.y = d.max_g;
    }
  }
}

void Entity::move() {
  if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::A)) {
    d.velocity.x = -d.speed;
  } else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::D)) {
    d.velocity.x = d.speed;
  } else {
    d.velocity.x = 0;
  }

  if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::W)) {
    d.velocity.y = -d.speed;
  }
}

void Entity::draw(sf::RenderTarget& target, sf::RenderStates states) const {
  target.draw(entitySprite, states);
}
