#include "../lib/game.hh"

Game* game;

int main()
{
  game = new Game();
  game->init("Project Chroma", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 640, 480, false);

  while(game->isRunning())
  {
    game->handleEvents();
    game->update();
    game->render();
  }

  game->terminate();
  return 0;
}