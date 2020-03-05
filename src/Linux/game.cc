#include "../lib/game.hh"
#include "../lib/logger.hh"

SDL_Renderer* Game::renderer = nullptr;
SDL_Event Game::event;
bool Game::running = true;

void Game::init(std::string title, int x, int y, int w, int h, bool fullscreen)
{
  Logger::init();
  Logger::log("init", "LogFile initialized");

  SDL_Init(SDL_INIT_EVERYTHING);
  Logger::log("init", "Initialized SDL");

  window = SDL_CreateWindow(title.c_str(), x, y, w, h, fullscreen ? SDL_WINDOW_FULLSCREEN : 0);
  Logger::log("init", "Created window");
  renderer = SDL_CreateRenderer(window, -1, 0);
  Logger::log("init", "Created renderer");

  SDL_SetRenderDrawBlendMode(renderer, SDL_BLENDMODE_BLEND);
  Logger::log("init", "Set Blendmode to BLEND");
}

void Game::handleEvents()
{
  SDL_WaitEvent(&event);
  if(event.type == SDL_QUIT)
  {
    Logger::log("event", "Received SDL_QUIT event");
    running = false;
  }
}

void Game::update() { }

void Game::render()
{
  SDL_SetRenderDrawColor(renderer, 0x00, 0x00, 0x00, 0xFF);
  SDL_RenderClear(renderer);



  SDL_RenderPresent(renderer);
}

void Game::terminate()
{
  SDL_DestroyRenderer(renderer);
  Logger::log("terminate", "Destroyed renderer");
  SDL_DestroyWindow(window);
  Logger::log("terminate", "Destroyed window");

  SDL_Quit();
  Logger::log("terminate", "Quitted SDL");

  Logger::terminate();
}

bool Game::isRunning() { return running; }