#ifndef GAME_H
#define GAME_H

#include <map>

#include "cocos2d.h"
#include "Layers/GameLayer.h"

class Game
{
private:
	cocos2d::CCArray *enemies;
	std::map<const char*, cocos2d::CCLayer*> layers;
	Plane *hero;

public:
	Game();
	~Game();

	void addEnemy(Plane *enemy);
	void removeEnemy(Plane *enemy);
	Plane* getNearestEnemy();
	void setHero(Plane *hero);
	Plane* getHero();
	void addLayer(const char *key, cocos2d::CCLayer *layer);
	cocos2d::CCLayer* getLayer(const char *key);

	static Game *sharedGame;
};

#endif