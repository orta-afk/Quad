#include "game.hpp"

int main(){
  Game game;
  game.isRunning();
  while(game.isRunning()){
    game.updateGame();
    game.renderGame();
  }  
  return 0;
}
