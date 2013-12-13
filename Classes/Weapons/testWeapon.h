#ifndef TESTWEAPON_H
#define TESTWEAPON_H

#include "cocos2d.h"
#include "Weapon.h"
#include "../Units/Plane.h"
#include "../Layers/HeroLayer.h"
#include "Game.h"

class testWeapon : public Weapon
{
public:
	testWeapon();

	void fire(float delta);
};

#endif