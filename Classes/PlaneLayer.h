#ifndef _PLANELAYER_H_
#define _PLANELAYER_H_

#include "cocos2d.h"
#include "Plane.h"
#include "HeroBulletLayer.h"

class PlaneLayer : public cocos2d::CCLayer
{
public:
	CREATE_FUNC(PlaneLayer);
	virtual bool init();
	void setBulletLayer(HeroBulletLayer *layer);
	void ccTouchesMoved(cocos2d::CCSet *pTouches, cocos2d::CCEvent *pEvent);
	void update(float delta);

	static Plane *Hero;
};

#endif