#include "Weapon.h"

#include "Game.h"

USING_NS_CC;

void Weapon::initWeapon()
{
	this->rotateEnabled = false;
	this->coolDown = 0;
	this->firingInterval = 1;
}

void Weapon::setFireInterval(float firingInterval)
{
	this->firingInterval = firingInterval;
}

void Weapon::enableRotate()
{
	this->rotateEnabled = true;
}

bool Weapon::isRotateEnabled()
{
	return rotateEnabled;
}

// children can run this function to get if the weapon ready to fire
bool Weapon::weaponReady(float delta)
{
	coolDown += delta;
	if (coolDown > firingInterval)
	{
		coolDown = 0;
		return true;
	}
	return false;
}

void Weapon::rotateWeapon()
{
	if(!isRotateEnabled()) return;

	CCPoint targetPos;
	if(getParent()->isEqual(Game::sharedGame->getHero()))
	{
		// if the plane which owns this weapon is hero, then aim at the nearest enemy
		// TO BE DONE
		targetPos = Game::sharedGame->getNearestEnemy()->getPosition();
	}
	else
	{
		// else aim at hero
		targetPos = Game::sharedGame->getHero()->getPosition();
	}

	CCPoint weaponPos = this->getParent()->convertToWorldSpace(getPosition());
	CCPoint diff = ccpSub(targetPos, weaponPos);

	setRotation(-1 * CC_RADIANS_TO_DEGREES(diff.getAngle()));
}