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

void Bullet::fly()
{
	runAction(CCMoveTo::create(40, ccpAdd(getPosition(), ccp(0, 10000))));
}

void Bullet::setDamage(float damage)
{
	this->damage = damage;
}

float Bullet::getDamage()
{
	return this->damage;
}