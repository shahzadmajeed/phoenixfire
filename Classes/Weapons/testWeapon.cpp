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