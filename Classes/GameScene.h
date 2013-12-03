#ifndef _GAMESCENE_H_
#define _GAMESCENE_H_

#include "cocos2d.h"
#include "GameLayer.h"
#include "PlaneLayer.h"
#include "BulletLayer.h"
#include "EnemyLayer.h"
#include "Enemy.h"

class GameScene : public cocos2d::CCScene
{
public:
	CREATE_FUNC(GameScene);
	virtual bool init();
	void update(float delta);
	
	GameLayer* gameLayer;
	EnemyLayer* enemyLayer;
	PlaneLayer* planeLayer;
	BulletLayer* bulletLayer;
};

#endif