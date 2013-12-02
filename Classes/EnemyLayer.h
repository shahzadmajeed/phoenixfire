#ifndef _ENEMYLAYER_H_
#define _ENEMYLAYER_H_

#include "cocos2d.h"

class EnemyLayer : public cocos2d::CCLayer
{
public:
	CREATE_FUNC(EnemyLayer);
	virtual bool init();
	void update(float delta);

	void addEnemy(float delta);
};

#endif