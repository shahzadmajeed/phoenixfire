#include "Game.h"

USING_NS_CC;

Game *Game::sharedGame = new Game();

Game::Game(void)
{
	hero = NULL;
}

void Game::setHero(Plane *hero)
{
	this->hero = hero;
}

Plane* Game::getHero()
{
	return this->hero;
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