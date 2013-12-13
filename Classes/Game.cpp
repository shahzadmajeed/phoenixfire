#include "Game.h"

USING_NS_CC;

Game *Game::sharedGame = new Game();

Game::Game(void)
{
}


void Game::addLayer(const char *key, CCLayer *layer)
{
	layers.insert(std::pair<const char*, CCLayer*>(key, layer));
}

CCLayer* Game::getLayer(const char *key)
{
	if (layers.count(key))
		return layers[key];
	else
		return NULL;
}