#ifndef TESTENEMY_H
#define TESTENEMY_H

#include "cocos2d.h"
#include "Plane.h"
#include "Weapons/testWeapon.h"

class TestEnemy : public Plane
{
private:
	bool init();

public:
	CREATE_FUNC(TestEnemy);
};

#endif