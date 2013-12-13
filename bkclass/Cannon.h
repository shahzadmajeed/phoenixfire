#ifndef _CANNON_H_
#define _CANNON_H_

#include "cocos2d.h"
#include "EnemyBulletLayer.h"

class Cannon : public cocos2d::CCSprite
{
private:
	EnemyBulletLayer *bulletLayer;
	float fireEnergyBar;
	float fireInterval;

public:
	static Cannon* create(const char *pszFileName, float fireInterval);
	void fire(float deltaTime);
	void setFireInterval(float fireInterval);
	void initFireEnergyBar();
	void setBulletLayer(EnemyBulletLayer *layer);
};

#endif