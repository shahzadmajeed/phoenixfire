#include "Bullet.h"

USING_NS_CC;

Bullet::Bullet(CCPoint *position)
{
	this->position = position;
}

CCPoint* Bullet::getPosition()
{
	return position;
}