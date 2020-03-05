#include "../lib/game.hh"
#include "../lib/logger.hh"
#include "../lib/util.hh"
#include "../lib/Objects/player.hh"

SDL_Renderer* Game::renderer = nullptr;
SDL_Event Game::event;
bool Game::running = true;
AssetManager* Game::assets = nullptr;

SDL_Rect Game::camera;
Player* player;

void Game::init(std::string title, int x, int y, int w, int h, bool fullscreen)
{
  Logger::init();
  Logger::log("init", "LogFile initialized");

  SDL_Init(SDL_INIT_EVERYTHING);
  window = SDL_CreateWindow(title.c_str(), x, y, w, h, fullscreen ? SDL_WINDOW_FULLSCREEN : 0);
  renderer = SDL_CreateRenderer(window, -1, 0);
  SDL_SetRenderDrawBlendMode(renderer, SDL_BLENDMODE_BLEND);
  Logger::log("init", "SDL Initialized");

  assets = new AssetManager();
  camera = Util::iSDL_Rect(0, 0, w, h);
  Logger::log("init", "Asset Manager and Camera created");

  assets->addSprite("missing", "dat/missing.png", 32, 32, 1);
  assets->addSprite("player", "dat/player_placeholder.png", 32, 32, 1, true);
  Logger::log("init", "Loaded sprites");

  assets->defineAnimation("player", "red", 0, 12, 100);
  assets->defineAnimation("player", "green", 1, 12, 100);
  assets->defineAnimation("player", "blue", 2, 12, 100);
  assets->defineAnimation("player", "yellow", 3, 12, 100);
  assets->playAnimation("player", "red");
  Logger::log("init", "Defined animations");

  player = new Player("player");
  Logger::log("init", "Created player");
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
  camera.x = player->pos.x - 320;
  camera.y = player->pos.y - 260;

  player->update();

  if(camera.x < 0) camera.x = 0;
  if(camera.y < 0) camera.y = 0;
  if(camera.x > camera.w) camera.x = camera.w;
  if(camera.y > camera.h) camera.y = camera.h;
}

void Game::render()
{
  SDL_SetRenderDrawColor(renderer, 0x00, 0x00, 0x00, 0xFF);
  SDL_RenderClear(renderer);

  player->draw();

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