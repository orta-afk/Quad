#include "game.hpp"

Game::Game() {
  initGame();
  windowPosX = videomode.getDesktopMode().size.x / 2;
  windowPosY = videomode.getDesktopMode().size.y / 2;
}

void Game::initGame() {
  initWindow();
  entity.initEntity();
  tilemap.initTilemap();
  tilemap.updateTilemap();
  window->setVerticalSyncEnabled(true);
}

void Game::renderGame() {
  window->clear(sf::Color::Black);
  window->draw(tilemap);
  entity.renderEntity(*window);
  window->display();
}

void Game::updateGame() {
  dt = clock.restart().asSeconds();
  entity.updateEntity(dt);
  updatePollEvent();
}

const bool Game::isRunning() const { return window->isOpen(); }

void Game::initWindow() {
  window = new sf::RenderWindow(sf::VideoMode({width, height}), title,
                                sf::Style::Titlebar | sf::Style::Close,
                                sf::State::Windowed);
  window->setMouseCursorVisible(false);
}

void Game::updatePollEvent() {
  while (const std::optional<sf::Event> event = window->pollEvent()) {
    if (event->is<sf::Event::Closed>()) {
      window->close();
    }
  }
}

Game::~Game() { delete window; }
