#ifndef GAMELAYER_H
#define GAMELAYER_H

#include "cocos2d.h"
#include "../Units/Plane.h"
#include "Units/TestHero1.h"
#include "Weapons/testWeapon.h"

class GameLayer : public cocos2d::CCLayer
{
private:
	bool init();

	virtual void registerWithTouchDispatcher();
	virtual bool ccTouchBegan(cocos2d::CCTouch *pTouch, cocos2d::CCEvent *pEvent);
	virtual void ccTouchMoved(cocos2d::CCTouch *pTouch, cocos2d::CCEvent *pEvent);
	void moveHero(cocos2d::CCTouch *pTouch);

public:
	Plane *hero;

	CREATE_FUNC(GameLayer);
};

#endif
