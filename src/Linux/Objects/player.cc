#include "../../lib/Objects/player.hh"
#include "../../lib/game.hh"
#include "../../lib/logger.hh"

Player::Player() { spriteID = "missing"; }
Player::Player(std::string nSpriteID) { spriteID = nSpriteID; }

void Player::changeColor()
{

}

void Player::update()
{
  Game::assets->getSprite(spriteID)->update();
}

void Player::draw()
{
  Game::assets->getSprite(spriteID)->draw();
}