#include "testWeapon.h"

USING_NS_CC;

bool testWeapon::init()
{
	if(!initWithFile("hero.png")) return false;

	initWeapon();
	setFireInterval(0.5f);
	setScale(0.3f);

	this->scheduleUpdate();

	return true;
}

// this evil weapon will hurt his owner!
void testWeapon::update(float delta)
{
	rotateWeapon(ccp(370, 1280));

	if (weaponReady(delta)) {
		GameLayer *layer = (GameLayer*)Game::sharedGame->getLayer("GameLayer");
		Plane *plane = (Plane*)layer->hero;

		plane->decreaseLife(10);
		CCLog("TestWeapon fired! Now our hero's life remain %f", plane->getLife());
	}
}