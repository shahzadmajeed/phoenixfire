#ifndef _BULLET_H_
#define _BULLET_H_

#include "cocos2d.h"

class Bullet : public cocos2d::CCSprite
{
private:
	float damage;
public:
	CREATE_FUNC(Bullet);
	static Bullet* createWithTexture(cocos2d::CCTexture2D *pTexture);
	void fly();
	void setDamage(float damage);
	float getDamage();


};

#endif