#ifndef _PLANE_H_
#define _PLANE_H_

#include "cocos2d.h"
#include "Bullet.h"
#include "BulletLayer.h"

class Plane : public cocos2d::CCSprite
{
private:
	float fireEnergyBar;
	float fireInterval;

public:
	static Plane* create(const char *pszFileName, float fireInterval);
	
	void moveTo(cocos2d::CCPoint destination);
	void fire(float deltaTime);
	void setFireInterval(float fireInterval);
	void initFireEnergyBar();
};

#endif