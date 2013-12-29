#ifndef WEAPON_H
#define WEAPON_H

#include "cocos2d.h"

class Weapon : public cocos2d::CCSprite
{
private:
	float firingInterval;
	float coolDown;

public:
	void initWeapon();
	void setFireInterval(float firingInterval);

	bool weaponReady(float delta);
	void rotateWeapon(cocos2d::CCPoint p);
};

#endif