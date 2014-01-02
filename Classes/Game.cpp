#include "Game.h"

USING_NS_CC;

Game *Game::sharedGame = new Game();

Game::Game(void)
{
	hero = NULL;
	enemies = CCArray::create();
	enemies->retain();
}

Game::~Game()
{
	enemies->release();
}

void Game::setHero(Plane *hero)
{
	this->hero = hero;
}

Plane* Game::getHero()
{
	return this->hero;
}

void Game::addEnemy(Plane *enemy)
{
	enemies->addObject(enemy);
}

void Game::removeEnemy(Plane *enemy)
{
	enemies->fastRemoveObject(enemy);
}

Plane* Game::getNearestEnemy()
{
	CCNode *nearest = NULL;
	CCObject *obj = NULL;
	CCARRAY_FOREACH(enemies, obj)
	{
		if (nearest == NULL) 
		{
			nearest = (CCNode*)obj;
			continue;
		}

		if (ccpDistance(hero->getPosition(), ((CCNode*)obj)->getPosition()) >
			ccpDistance(hero->getPosition(), nearest->getPosition()))
		{
			nearest = (CCNode*)obj;
		}
	}

	return (Plane*)nearest;
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