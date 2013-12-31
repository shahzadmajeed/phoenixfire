#ifndef PLANE_H
#define PLANE_H

#include "cocos2d.h"
#include "CocoStudio/Armature/CCArmature.h"
#include "Weapons/Bullets/Bullet.h"

class Plane : public cocos2d::extension::CCArmature
{
public:
	enum Status
	{
		ALIVE,
		DEAD,
	};

	static Plane* create(const char *name) 
	{ 
		Plane *pRet = new Plane();
		if (pRet && pRet->init(name))
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

	bool init(const char *name);

	void setStatus(enum Status status);
	enum Status getStatus();
	void collisionDetect(Bullet *bullet);
	void setLife(float life);
	float getLife();
	void decreaseLife(float value);


private:
	enum Status status;
	float life;
};

#endif