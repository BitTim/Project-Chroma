#include "../lib/game.hh"
#include "../lib/logger.hh"
#include "../lib/util.hh"

SDL_Renderer* Game::renderer = nullptr;
SDL_Event Game::event;
bool Game::running = true;
AssetManager* Game::assets = nullptr;
SDL_Rect Game::camera;

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

  assets = new AssetManager();
  Logger::log("init", "Created AssetManager");

  camera = Util::iSDL_Rect(0, 0, w, h);
  Logger::log("init", "Created Camera");

  assets->addTexture("missing", "dat/missing.png");
}

void Game::handleEvents()
{
  SDL_PollEvent(&event);
  if(event.type == SDL_QUIT)
  {
    Logger::log("event", "Received SDL_QUIT event");
    running = false;
  }
}

void Game::update()
{
  //camera.x = player.getComponent<TransformComponent>().pos.x - 320;
  //camera.y = player.getComponent<TransformComponent>().pos.y - 260;

  if(camera.x < 0) camera.x = 0;
  if(camera.y < 0) camera.y = 0;
  if(camera.x > camera.w) camera.x = camera.w;
  if(camera.y > camera.h) camera.y = camera.h;
}

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