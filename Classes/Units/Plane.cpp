#include "Plane.h"

USING_NS_CC;

bool Plane::init(const char *name)
{
	if (!CCArmature::init(name)) return false;

	this->setLife(100);
	this->status = ALIVE;

	return true;
}

void Plane::setStatus(enum Status status)
{
	this->status = status;
}

Plane::Status Plane::getStatus()
{
	return status;
}

void Plane::collisionDetect(Bullet *bullet)
{
	// to be done
}

void Plane::setLife(float life)
{
	if (life < 0) life = 0;
	this->life = life;
}

float Plane::getLife()
{
	return this->life;
}

void Plane::decreaseLife(float value)
{
	this->life -= value;
	if (life <= 0){
		this->setStatus(Plane::DEAD);
		this->life = 0;
	}
}
