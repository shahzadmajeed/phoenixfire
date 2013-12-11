#include "Plane.h"

USING_NS_CC;

void Plane::setLife(float life)
{
	this->life = life;
}

float Plane::getLife()
{
	return this->life;
}

void Plane::moveTo(CCPoint destination)
{
	setPosition(destination);
}