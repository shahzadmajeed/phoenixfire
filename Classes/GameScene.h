#ifndef _GAMESCENE_H_
#define _GAMESCENE_H_

#include "cocos2d.h"
#include "GameLayer.h"
#include "PlaneLayer.h"
#include "BulletLayer.h"

class GameScene : public cocos2d::CCScene
{
public:
	GameScene();
	~GameScene();
	CREATE_FUNC(GameScene);
	virtual bool init();
	
	GameLayer* gameLayer;
	PlaneLayer* planeLayer;
	BulletLayer* bulletLayer;
};

#endif