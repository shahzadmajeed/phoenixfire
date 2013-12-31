#ifndef BULLET_H
#define BULLET_H

#include "cocos2d.h"

class Bullet : public cocos2d::CCSprite
{
private:
	float speed;
	float damage;

public:
	CREATE_FUNC(Bullet);
	static Bullet* create(const char *type, float speed, float damage) 
	{ 
		Bullet *pRet = new Bullet();
		if (pRet && pRet->init(type, speed, damage))
		{
			pRet->autorelease();
			return pRet;
		}
		else
		{
			delete pRet;
			pRet = NULL;
			return NULL;
		}
	}

	virtual bool init();
	virtual bool init(const char *type, float speed, float damage);

	virtual void update(float delta);

	float getSpeed();
	void setSpeed(float speed);
	float getDamage();
	void setDamage(float damage);
};

#endif