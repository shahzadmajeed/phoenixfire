#include "TestBullet.h"

USING_NS_CC;

bool TestBullet::init()
{
	if(!Bullet::initWithFile("bullet.png")) return false;

	Bullet::initBullet();

	setDamage(10);
	speed = 1200;

	return true;
}

void TestBullet::update(float delta)
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