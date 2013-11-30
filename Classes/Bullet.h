#ifndef _BULLET_H_
#define _BULLET_H_

#include "cocos2d.h"

class Bullet : public cocos2d::CCSprite
{
private:
	int speed;

	cocos2d::CCSprite *bulletSprite;

public:
	static Bullet* create(const char *pszFileName, cocos2d::CCPoint position, int speed);
	void setBulletPosition(cocos2d::CCPoint position);
	void setBulletSpeed(int speed);
	void updateBullet(float delta);
};

#endif