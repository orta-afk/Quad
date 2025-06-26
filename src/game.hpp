#pragma once

#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>

#include "entity.hpp"
#include "tilemap.hpp"
#include "collider.hpp"

class Game {
public:
  Game();
  void renderGame();
  void updateGame();
  const bool isRunning();
  ~Game();

public:
  bool running;
  bool collided;

private:
  void initStuff();
  void initWindow();
  void handlePollEvents();

private:
  sf::Clock clock;
  const char *title;
  sf::RenderWindow* window;
  const unsigned int width;
  const unsigned int height;

private:
  Entity entity;
  Tilemap tilemap;
  Collider collider;
};
