#pragma once

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <array>

enum class tiles : int {
  backgroundTile,
  ground,
};

class Tilemap : public sf::Drawable, sf::Transform{
public:
  Tilemap();
  void initTilemap();
  void updateTilemap();
  ~Tilemap();

private:
  static const int mapWidth = 80;
  static const int mapHeight = 45;
  static const int tileSize = 16;
  std::array<std::array<int, mapWidth>, mapHeight> map;
  sf::Texture texture;
  sf::VertexArray vert;

private:
    void draw(sf::RenderTarget& target, sf::RenderStates states) const override
    {
        states.texture = &texture;
        target.draw(vert, states);
    }
};
