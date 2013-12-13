#ifndef HEROLAYER_H
#define HEROLAYER_H

#include "cocos2d.h"
#include "../Units/Plane.h"

class HeroLayer : public cocos2d::CCLayer
{
private:
	Plane *hero;

	bool init(Plane *hero);
	void moveHero(cocos2d::CCTouch *pTouch);

	virtual void registerWithTouchDispatcher();
	virtual bool ccTouchBegan(cocos2d::CCTouch *pTouch, cocos2d::CCEvent *pEvent);
	virtual void ccTouchMoved(cocos2d::CCTouch *pTouch, cocos2d::CCEvent *pEvent);

public:
	static enum Tags
	{
		HERO = 0,
	};

	static HeroLayer* create(Plane *hero);
};

#endif
