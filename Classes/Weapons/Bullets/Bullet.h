#ifndef BULLET_H
#define BULLET_H

#include "cocos2d.h"

class Bullet : public cocos2d::CCSprite
{
private:
	float damage;

public:
	void initBullet();

	float getDamage();
	void setDamage(float damage);
};

#endif