#include "Bullet.h"

USING_NS_CC;

Bullet* Bullet::createWithTexture(CCTexture2D *pTexture)
{
    Bullet *bullet = new Bullet();
    if (bullet && bullet->initWithTexture(pTexture))
    {
		bullet->setDamage(10);
        bullet->autorelease();
        return bullet;
    }
    CC_SAFE_DELETE(bullet);
    return NULL;
}

void Bullet::fly(float angle)
{
	CCPoint direction = ccp(10000, 0);
	direction = ccpRotate(direction, ccpForAngle(angle));
	float a = angle / PI * 180;
	setRotation(- (angle / PI * 180) + 90);
	runAction(CCMoveTo::create(40, ccpAdd(getPosition(), direction)));
}

void Bullet::setDamage(float damage)
{
	this->damage = damage;
}

float Bullet::getDamage()
{
	return this->damage;
}