#include "game.hpp"

Game::Game() : width(720), height(480), title("quad"), window(nullptr){
  initWindow();
  initStuff();
}

void Game::initWindow(){
  window = new sf::RenderWindow(sf::VideoMode({width,height}), title, sf::Style::Titlebar | sf::Style::Close, sf::State::Windowed);
}

void Game::initStuff(){
  entity.initEntity();  
  tilemap.initTilemap();
  tilemap.makeTile();
}

const bool Game::isRunning(){
  if(window->isOpen()){
    running = true;
  }
  return running;
}

void Game::updateGame(){
  handlePollEvents();
  float dt = clock.restart().asSeconds();
  entity.updateEntity(dt);
}

void Game::handlePollEvents(){
  while(const std::optional<sf::Event> event = window->pollEvent()){
    if(event->is<sf::Event::Closed>()){
      window->close();
    }
    if(const auto* key = event->getIf<sf::Event::KeyPressed>()){
      if(key->scancode == sf::Keyboard::Scancode::Escape){
        window->close();
      }
    }
  }
}

void Game::renderGame(){
  window->clear(sf::Color::Black);
  window->draw(tilemap);
  window->draw(entity);
  window->display();  
}

Game::~Game(){
  delete window;
}
