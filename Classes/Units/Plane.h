#ifndef PLANE_H
#define PLANE_H

#include "cocos2d.h"
#include "../Weapons/Weapon.h"

class Plane : public cocos2d::CCSprite
{
public:
	enum Status
	{
		ALIVE,
		DEAD,
	};

	void initPlane();

	void setStatus(Status status);
	Status getStatus();

	void setLife(float life);
	float getLife();
	void decreaseLife(float value);


private:
	Status status;
	float life;
};

#endif