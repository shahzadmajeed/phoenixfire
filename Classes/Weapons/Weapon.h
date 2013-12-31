#ifndef WEAPON_H
#define WEAPON_H

#include "cocos2d.h"

class Weapon : public cocos2d::CCSprite
{
private:
	bool rotateEnabled;
	float firingInterval;
	float coolDown;

public:
	void initWeapon();
	void setFireInterval(float firingInterval);

	void enableRotate();
	bool isRotateEnabled();

	bool weaponReady(float delta);
	void rotateWeapon();
};

#endif