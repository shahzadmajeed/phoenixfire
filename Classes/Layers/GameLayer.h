#ifndef GAMELAYER_H
#define GAMELAYER_H

#include "cocos2d.h"
#include "../Units/Plane.h"
#include "Weapons/Bullets/Bullet.h"

class GameLayer : public cocos2d::CCLayer
{
private:
	cocos2d::CCArray *enemies;
	cocos2d::CCSpriteBatchNode *gameBatch;

	bool init();

	virtual void registerWithTouchDispatcher();
	virtual bool ccTouchBegan(cocos2d::CCTouch *pTouch, cocos2d::CCEvent *pEvent);
	virtual void ccTouchMoved(cocos2d::CCTouch *pTouch, cocos2d::CCEvent *pEvent);
	void moveHero(cocos2d::CCTouch *pTouch);

public:
	GameLayer();
	CREATE_FUNC(GameLayer);

	void initHero();
	void createEnemy();

	Plane* getHero();
	void addBullet(Bullet *bullet);
};

#endif
