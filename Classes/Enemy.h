#ifndef _ENEMY_H_
#define _ENEMY_H_

#include "cocos2d.h"
#include "Bullet.h"
#include "Cannon.h"
#include "EnemyBulletLayer.h"

class Enemy : public cocos2d::CCSprite
{
private:
	float life;
	void foreverMove();
	void addCannons();

public:
	static Enemy* create(const char *pszFileName);
	
	void move();
	boolean detectCollusion(Bullet *bullet);
	void setLife(float life);
	float getLife();
	void setBulletLayer(EnemyBulletLayer *layer);
	void fire(float deltaTime);
};

#endif