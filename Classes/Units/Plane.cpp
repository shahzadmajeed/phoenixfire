#include "Plane.h"

USING_NS_CC;

bool Plane::initWithFile(const char *pszFilename)
{
	if (CCSprite::initWithFile(pszFilename))
	{
		this->setLife(100);
		this->setStatus(Plane::Status::ALIVE);
		this->scheduleUpdate();

		return true;
	}
	return false;
}
void Plane::setStatus(Status status)
{
	this->status = status;
}

Plane::Status Plane::getStatus()
{
	return status;
}

void Plane::setLife(float life)
{
	this->life = life;
	if (life <= 0) this->setStatus(Plane::DEAD);
}

float Plane::getLife()
{
	return this->life;
}

void Plane::addWeapon(Weapon *weapon)
{
	weapons.push_back(weapon);
}

void Plane::update(float delta)
{
	if (getStatus() == Plane::DEAD) return;

	std::vector<Weapon*>::iterator iter = weapons.begin();
	while (iter != weapons.end())
	{
		Weapon *weapon = *iter;
		weapon->fire(delta);
		iter++;
	}
}

void Plane::moveTo(CCPoint destination)
{
	if (getStatus() == Plane::DEAD) return;
	
	CCLog("hero moving");
	setPosition(destination);
}