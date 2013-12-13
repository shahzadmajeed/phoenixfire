#include "Weapon.h"

USING_NS_CC;

Weapon::Weapon(float firingInterval)
{
	this->coolDown = 0;
	this->firingInterval = firingInterval;
}

// children can run this function to get if the weapon ready to fire
bool Weapon::weaponReady(float delta)
{
	coolDown += delta;
	if (coolDown > firingInterval)
	{
		coolDown = 0;
		CCLog("Weapon ready");
		return true;
	}
	return false;
}

// make it a pure virtual function
//void Weapon::fire(float delta)
//{
//	coolDown += delta;
//	if (coolDown > firingInterval)
//	{
//
//	}
//}