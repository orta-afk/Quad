#include "game.hpp"

Game::Game() : window(nullptr){
  win.width = 720;
  win.height = 480;
  win.title = "Quad";
  initWindow();
  initStuff();
}

void Game::initWindow(){
  sf::VideoMode desktopMode = sf::VideoMode::getDesktopMode();
  window = new sf::RenderWindow(sf::VideoMode({win.width,win.height}), win.title, sf::Style::Titlebar | sf::Style::Close, sf::State::Windowed);
  sf::Vector2u windowSize = window->getSize();
  sf::Vector2i centeredPosition(desktopMode.size.x / 2 - windowSize.x / 2,
                                desktopMode.size.y / 2 - windowSize.y / 2);
  window->setPosition(centeredPosition);
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
  collided = collider.isCollided();
  entity.updateEntity(dt, collided);
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
