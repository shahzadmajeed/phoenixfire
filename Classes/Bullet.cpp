#include "Bullet.h"

USING_NS_CC;

Bullet* Bullet::createWithTexture(CCTexture2D *pTexture)
{
    Bullet *pobSprite = new Bullet();
    if (pobSprite && pobSprite->initWithTexture(pTexture))
    {
        pobSprite->autorelease();
        return pobSprite;
    }
    CC_SAFE_DELETE(pobSprite);
    return NULL;
}

void Bullet::fly()
{
	runAction(CCMoveTo::create(40, ccpAdd(getPosition(), ccp(0, 10000))));
}