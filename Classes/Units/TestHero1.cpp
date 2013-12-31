#include "TestHero1.h"

USING_NS_CC;

bool TestHero1::init()
{
	
    if (!Plane::init("hero1")) return false;
	initPlane();

	testWeapon *mainWeapon = testWeapon::create();
	mainWeapon->setRotation(-90);
	mainWeapon->setPosition(ccp(75, 125));

	testWeapon *leftWeapon = testWeapon::create();
	leftWeapon->setFireInterval(0.2f);
	leftWeapon->setRotation(-110);
	leftWeapon->setPosition(ccp(4, 50));

	testWeapon *leftMidWeapon = testWeapon::create();
	leftMidWeapon->setFireInterval(0.4f);
	leftMidWeapon->setRotation(-100);
	leftMidWeapon->setPosition(ccp(32, 46));

	testWeapon *rightWeapon = testWeapon::create();
	rightWeapon->setFireInterval(0.2f);
	rightWeapon->setRotation(-70);
	rightWeapon->setPosition(ccp(148, 50));

	testWeapon *rightMidWeapon = testWeapon::create();
	rightMidWeapon->setFireInterval(0.4f);
	rightMidWeapon->setRotation(-80);
	rightMidWeapon->setPosition(ccp(118, 46));

	addChild(mainWeapon);
	addChild(leftWeapon);
	addChild(leftMidWeapon);
	addChild(rightWeapon);
	addChild(rightMidWeapon);

	return true;
}