#pragma once

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>

enum class tiles : int{
  ground = 0,
  background = 2,
};

class Tilemap : public sf::Drawable, sf::Transform {
public:
  Tilemap();
  void initTilemap();
  void updateTilemap();
  ~Tilemap();

private:
  sf::Texture texture;
  sf::VertexArray vert;
  sf::FloatRect tilesBoundingBox;
  static const int width = 80;
  static const int height = 45;
  static const int size = 16;
  std::array<std::array<int, height>, width> map;

private:
  void draw(sf::RenderTarget& target, sf::RenderStates states) const override{
    states.texture = &texture;
    target.draw(vert, states);
  }
};
