#include "TestBullet1.h"

USING_NS_CC;

bool TestBullet1::init()
{
	if(!initWithSpriteFrameName("enemy_bullet.png")) return false;

	Bullet::initBullet();

	setDamage(10);
	speed = 700;

	return true;
}

void TestBullet1::update(float delta)
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