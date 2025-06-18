#pragma once

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>

class Game {
public:
  Game();
  void initGame();
  void updateGame();
  void renderGame();
  const bool isRunning() const;
  ~Game();

private:
  sf::RenderWindow* window = nullptr;
  const unsigned int width = 800;
  const unsigned int height = 480;
  const char* title = "Quad";

private:
  void initWindow();
  void updatePollEvent();
};
