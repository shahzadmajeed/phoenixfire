#include "Weapon.h"

USING_NS_CC;

void Weapon::initWeapon()
{
	this->coolDown = 0;
	this->firingInterval = 1;
}

void Weapon::setFireInterval(float firingInterval)
{
	this->firingInterval = firingInterval;
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

void Weapon::rotateWeapon(CCPoint targetPos)
{
	CCPoint weaponPos = this->getParent()->convertToWorldSpace(getPosition());
	CCPoint diff = ccpSub(weaponPos, targetPos);

	setRotation(-1 * CC_RADIANS_TO_DEGREES(diff.getAngle() + M_PI / 2));
}