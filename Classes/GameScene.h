#ifndef GAMESCENE_H
#define GAMESCENE_H

#include "cocos2d.h"
#include "Layers/BackgroundLayer.h"
#include "Layers/GameLayer.h"
#include "Game.h"

class GameScene : public cocos2d::CCScene
{
private:
	virtual bool init();

public:
	CREATE_FUNC(GameScene);
};

#endif