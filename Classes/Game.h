#ifndef __GAME_SCENE_H__
#define __GAME_SCENE_H__

#include "cocos2d.h"

class Game : public cocos2d::CCLayerColor
{
private:
	cocos2d::CCSprite *pHero;
	void ccTouchesMoved(cocos2d::CCSet *pTouches, cocos2d::CCEvent *pEvent);
	void update(float delta);

public:
    virtual bool init();

    static cocos2d::CCScene* scene();
    
    CREATE_FUNC(Game);
};

#endif // __HELLOWORLD_SCENE_H__
