#include "Bullet.h"

USING_NS_CC;

Bullet* Bullet::create(const char *pszFileName,CCPoint position, int speed)
{
	Bullet *bullet = new Bullet();
	if (bullet && bullet->initWithFile(pszFileName))
    {
		bullet->setPosition(position);
		bullet->setBulletSpeed(speed);
        bullet->autorelease();
		return bullet;
	}
	CC_SAFE_DELETE(bullet);
	return NULL;
}

void Bullet::updateBullet(float delta)
{
	setPositionY(getPositionY() + speed * delta);
}

void Bullet::setBulletSpeed(int speed)
{
	this->speed = speed;
}