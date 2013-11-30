#include "Bullet.h"

USING_NS_CC;

Bullet* Bullet::create(const char *pszFileName)
{
	Bullet *bullet = new Bullet();
	if (bullet && bullet->initWithFile(pszFileName))
    {
        bullet->autorelease();
		return bullet;
	}
	CC_SAFE_DELETE(bullet);
	return NULL;
}

void Bullet::fly()
{
	runAction(CCMoveTo::create(50, ccpAdd(getPosition(), ccp(0, 10000))));
}