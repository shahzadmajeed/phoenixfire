#ifndef ENEMY_H
#define ENEMY_H

#include "cocos2d.h"
#include "Units/Plane.h"

class Enemy : public Plane
{
private:
	bool init(const char *name);
	void move();

public:
	static Enemy* create(const char *name) 
	{ 
		Enemy *pRet = new Enemy();
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
};

#endif