#include "Bullet.h"

USING_NS_CC;

bool Bullet::init()
{
	if(!initWithSpriteFrameName("enemy_bullet.png")) return false;

	setDamage(10);
	setSpeed(700);

	scheduleUpdate();

	return true;
}

bool Bullet::init(const char *type, float speed, float damage)
{
	if(!initWithSpriteFrameName(type)) return false;

	setDamage(damage);
	setSpeed(speed);

	scheduleUpdate();

	return true;
}

void Bullet::setSpeed(float speed)
{
	this->speed = speed;
}

float Bullet::getSpeed()
{
	return speed;
}

void Bullet::setDamage(float damage)
{
	this->damage = damage;
}

float Bullet::getDamage()
{
	return damage;
}

void Bullet::update(float delta)
{
	if(getPositionY() > 1280 || getPositionX() < 0 ||
		getPositionX() > 760 || getPositionY() < 0)
		removeFromParent();

	float angle = getRotation();
	angle = CC_DEGREES_TO_RADIANS(-angle);
	float x = speed * delta * cosf(angle);
	float y = speed * delta * sinf(angle);

	setPosition(ccpAdd(getPosition(), ccp(x, y)));
}