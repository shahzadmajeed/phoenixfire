#ifndef TESTWEAPON_H
#define TESTWEAPON_H

#include "cocos2d.h"
#include "Weapon.h"
#include "../Units/Plane.h"
#include "Bullets/TestBullet.h"
#include "Game.h"

class testWeapon : public Weapon
{
public:
	CREATE_FUNC(testWeapon);
	virtual bool init();

	virtual void update(float delta);
};

#endif