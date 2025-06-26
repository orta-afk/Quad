#pragma once

#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>

#include "entity.hpp"
#include "tilemap.hpp"
#include "collider.hpp"

struct windowData{
  std::string title;
  unsigned int width;
  unsigned int height;
};

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
  windowData win;
  sf::Clock clock;
  sf::RenderWindow* window;

private:
  Entity entity;
  Tilemap tilemap;
  Collider collider;
};
