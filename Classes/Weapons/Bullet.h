#ifndef BULLET_H
#define BULLET_H

#include "cocos2d.h"

class Bullet : cocos2d::CCSprite
{
private:
	float damage;

public:
	virtual void fly();
};

#endif