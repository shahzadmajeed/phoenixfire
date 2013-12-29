#ifndef TESTHERO1_H
#define TESTHERO1_H

#include "cocos2d.h"
#include "Plane.h"
#include "Weapons/testWeapon.h"

class TestHero1 : public Plane
{
private:
	bool init();

public:
	CREATE_FUNC(TestHero1);
};

#endif