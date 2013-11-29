#ifndef _BULLET_H_
#define _BULLET_H_

#include "cocos2d.h"

static const float BULLET_INTERVAL = 2;
static const int BULLET_SPEED = 200;

class Bullet
{
private:
	cocos2d::CCPoint *position;

public:
	cocos2d::CCPoint* getPosition();
	Bullet(cocos2d::CCPoint *position);
};

#endif