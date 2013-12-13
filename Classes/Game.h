#ifndef GAME_H
#define GAME_H

#include <string>
#include <map>

#include "cocos2d.h"
#include "Layers/HeroLayer.h"

class Game
{
private:
	std::map<const char*, cocos2d::CCLayer*> layers;

public:
	Game();
	void addLayer(const char *key, cocos2d::CCLayer *layer);
	cocos2d::CCLayer* getLayer(const char *key);

	static Game *sharedGame;
};

#endif