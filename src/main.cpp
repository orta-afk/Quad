#include "game.hpp"

int main(){
  Game game;
  while(game.isRunning()){
    game.updateGame();
    game.renderGame();
  }  
  return 0;
}
