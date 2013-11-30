#ifndef __GAME_SCENE_H__
#define __GAME_SCENE_H__

#include "cocos2d.h"
#include "Plane.h"

class Game : public cocos2d::CCLayerColor
{
private:
	Plane *Hero;
	cocos2d::CCSet *bulletsList;

	void ccTouchesMoved(cocos2d::CCSet *pTouches, cocos2d::CCEvent *pEvent);
	void update(float delta);

public:
	cocos2d::CCSize visibleSize;

    virtual bool init();
    static cocos2d::CCScene* scene();
    
    CREATE_FUNC(Game);
};

#endif // __HELLOWORLD_SCENE_H__
