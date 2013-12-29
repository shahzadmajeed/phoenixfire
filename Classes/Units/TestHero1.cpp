#include "TestHero1.h"

USING_NS_CC;

bool TestHero1::init()
{
    if (!initWithFile("hero.png")) return false;
	initPlane();

	testWeapon *mainWeapon = testWeapon::create();
	CCPoint p = convertToNodeSpace(getPosition());
	mainWeapon->setPosition(p);

	addChild(mainWeapon);

	return true;
}