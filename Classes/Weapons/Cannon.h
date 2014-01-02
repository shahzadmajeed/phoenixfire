#ifndef CANNON_H
#define CANNON_H

#include "cocos2d.h"
#include "Weapon.h"
#include <string>

class Cannon : public Weapon
{
// TO BE DONE: let create function input a bullet factory, in order to DIY cannon.
private:
	std::string bulletType;
	float bulletSpeed;
	float bulletDamage;

public:
	static Cannon* create(float fireinterval, bool Rotatable,const char *bulletType,  float speed, float damage)
	{
		Cannon *pRet = new Cannon();
		if (pRet && pRet->init(fireinterval, Rotatable, bulletType, speed, damage))
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
	virtual bool init(float fireinterval, bool Rotatable, const char *bulletType, float speed, float damage);

	virtual void update(float delta);
};

#endif