#include "TestHero1.h"

USING_NS_CC;

TestHero1* TestHero1::create()
{
    TestHero1 *pobSprite = new TestHero1();
    if (pobSprite && pobSprite->initWithFile("hero.png"))
    {
        pobSprite->autorelease();
        return pobSprite;
    }
    CC_SAFE_DELETE(pobSprite);
    return NULL;
}