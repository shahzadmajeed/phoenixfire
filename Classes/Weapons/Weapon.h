#ifndef WEAPON_H
#define WEAPON_H

#include "cocos2d.h"

class Weapon
{
private:
	float firingInterval;
	float coolDown;

public:
	Weapon(float firingInterval);

	bool weaponReady(float delta);
	virtual void fire(float delta)=0;
};

#endif