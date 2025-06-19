#pragma once

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>

#include "SFML/System/Clock.hpp"
#include "entity.hpp"

class Game {
private:
  Entity entity;

public:
  Game();
  void initGame();
  void updateGame();
  void renderGame();
  const bool isRunning() const;
  ~Game();

private:
  sf::Clock clock;
  sf::RenderWindow* window = nullptr;
  const unsigned int width = 800;
  const unsigned int height = 480;
  const char* title = "Quad";
  float dt;

private:
  void initWindow();
  void updatePollEvent();
};
