#ifndef _ENEMY_H_
#define _ENEMY_H_

#include "cocos2d.h"
#include "Bullet.h"

class Enemy : public cocos2d::CCSprite
{
private:
	float life;
	void foreverMove();

public:
	static Enemy* create(const char *pszFileName);
	
	void move();
	float hitedByBullet(Bullet *bullet);
	void setLife(float life);
	float getLife();
};

#endif