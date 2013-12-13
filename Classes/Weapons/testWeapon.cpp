#include "testWeapon.h"

USING_NS_CC;

// also call super class's constructor to set fire interval
testWeapon::testWeapon(): Weapon(1)
{
}

// this evil weapon will hurt his owner!
void testWeapon::fire(float delta)
{
	if (weaponReady(delta)) {
		CCLayer *layer = Game::sharedGame->getLayer("HeroLayer");
		Plane *plane = (Plane*)layer->getChildByTag(HeroLayer::Tags::HERO);
		plane->setLife(plane->getLife() - 10);
		CCLog("TestWeapon fired! Now our hero's life remain %f", plane->getLife());
	}
}