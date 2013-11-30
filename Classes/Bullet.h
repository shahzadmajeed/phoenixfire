#ifndef _BULLET_H_
#define _BULLET_H_

#include "cocos2d.h"

class Bullet : public cocos2d::CCSprite
{
private:
	int speed;

	cocos2d::CCSprite *bulletSprite;

public:
	static Bullet* create(const char *pszFileName);
	void fly();
};

#endif