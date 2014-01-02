#include "PlaneFactory.h"

#include "Weapons/Cannon.h"
#include "Units/Enemy.h"

USING_NS_CC;

Plane* PlaneFactory::createPlane(PlaneType type)
{
	Plane *unit = NULL;

	switch (type)
	{
	case PlaneType::HERO1:
		{
			unit = Plane::create("hero1");

			Cannon *mainWeapon = Cannon::create();
			mainWeapon->setRotation(-90);
			mainWeapon->setPosition(ccp(0, 5));

			Cannon *leftWeapon = Cannon::create();
			leftWeapon->setFireInterval(0.2f);
			leftWeapon->setRotation(-110);
			leftWeapon->setPosition(ccp(-80, -55));

			Cannon *leftMidWeapon = Cannon::create();
			leftMidWeapon->setFireInterval(0.4f);
			leftMidWeapon->setRotation(-100);
			leftMidWeapon->setPosition(ccp(-50, -60));

			Cannon *rightWeapon = Cannon::create();
			rightWeapon->setFireInterval(0.2f);
			rightWeapon->setRotation(-70);
			rightWeapon->setPosition(ccp(70, -55));

			Cannon *rightMidWeapon = Cannon::create();
			rightMidWeapon->setFireInterval(0.4f);
			rightMidWeapon->setRotation(-80);
			rightMidWeapon->setPosition(ccp(40, -60));

			unit->addChild(mainWeapon);
			unit->addChild(leftWeapon);
			unit->addChild(leftMidWeapon);
			unit->addChild(rightWeapon);
			unit->addChild(rightMidWeapon);

			return unit;
		}
	case PlaneType::ENEMY1:
		{
			unit = Enemy::create("enemy1");

			Cannon *weapon1 = Cannon::create();
			weapon1->setFireInterval(0.4f);
			weapon1->enableRotate();
			weapon1->setPosition(unit->convertToNodeSpace(unit->getPosition()));

			unit->addChild(weapon1, 2);

			return unit;
		}
	default:
		{
			return NULL;
		}
	}
}