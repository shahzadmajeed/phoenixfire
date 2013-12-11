#ifndef PLANE_H
#define PLANE_H

#include "cocos2d.h"
//#include "../Weapons/Weapon.h"

class Plane : public cocos2d::CCSprite
{
private:
	float life;
	//cocos2d::CCArray *weapons;

public:
	void setLife(float life);
	float getLife();

	//void addWeapon(Weapon *weapon);
	//cocos2d::CCArray getWeapons();

	virtual void moveTo(cocos2d::CCPoint destination);
};

#endif