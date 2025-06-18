#include "game.hpp"

Game::Game(){
  initGame();
}

void Game::initGame(){
  initWindow(); 
  entity.initEntity();
  window->setVerticalSyncEnabled(true);
}

void Game::renderGame(){
  window->clear(sf::Color::Black);
  entity.renderEntity(*window);
  window->display();  
}

void Game::updateGame(){
  entity.updateEntity();
  updatePollEvent();  
}

const bool Game::isRunning() const {
  return window->isOpen();
}

void Game::initWindow(){
  window = new sf::RenderWindow(sf::VideoMode({width, height}), title, sf::Style::Titlebar | sf::Style::Close, sf::State::Windowed);
}

void Game::updatePollEvent(){
  while(const std::optional<sf::Event> event = window->pollEvent()){
    if(event->is<sf::Event::Closed>()){
      window->close();
    }
  }
}

Game::~Game(){
  delete window;  
}
