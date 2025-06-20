#pragma once

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>

#include "entity.hpp"
#include "tilemap.hpp"

class Game {
private:
  Entity entity;
  Tilemap tilemap;

public:
  Game();
  void initGame();
  void updateGame();
  void renderGame();
  const bool isRunning() const;
  ~Game();

private:
  float dt;
  int windowPosX;
  int windowPosY;
  sf::Clock clock;
  sf::RenderWindow *window = nullptr;
  sf::VideoMode videomode;
  const unsigned int width = 1280;
  const unsigned int height = 720;
  const char *title = "Quad";

private:
  void initWindow();
  void updatePollEvent();
};
