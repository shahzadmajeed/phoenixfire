#include "testWeapon.h"

USING_NS_CC;

bool testWeapon::init()
{
	if(!Weapon::init()) return false;

	initWeapon();
	setFireInterval(0.1f);

	this->scheduleUpdate();

	return true;
}

// a canon
void testWeapon::update(float delta)
{
	if (weaponReady(delta)) {
		TestBullet *bullet = TestBullet::create();
		bullet->setPosition(getParent()->convertToWorldSpace(getPosition()));
		bullet->setRotation(getRotation());

		GameLayer *layer = (GameLayer*)Game::sharedGame->getLayer("GameLayer");
		layer->addBullet(bullet);
	}
}

// this evil weapon will hurt his owner!
//void testWeapon::update(float delta)
//{
//	rotateWeapon(ccp(370, 1280));
//
//	if (weaponReady(delta)) {
//		GameLayer *layer = (GameLayer*)Game::sharedGame->getLayer("GameLayer");
//		Plane *plane = (Plane*)layer->hero;
//
//		plane->decreaseLife(10);
//		CCLog("TestWeapon fired! Now our hero's life remain %f", plane->getLife());
//	}
//}