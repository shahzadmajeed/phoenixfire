#include "HeroLayer.h"

USING_NS_CC;

HeroLayer* HeroLayer::create(Plane *hero)
{
	HeroLayer *heroLayer = new HeroLayer();
	if (heroLayer && heroLayer->init(hero))
	{
		heroLayer->autorelease();
		return heroLayer;
	}
	CC_SAFE_DELETE(heroLayer);
	return NULL;
}

bool HeroLayer::init(Plane *hero)
{
	if (!CCLayer::init()) return false;

	// init Hero
	this->hero = hero;
	addChild(this->hero, 0, Tags::HERO);

	setTouchEnabled(true);
    
    return true;
}

void HeroLayer::registerWithTouchDispatcher()
{
	CCDirector::sharedDirector()->getTouchDispatcher()->addTargetedDelegate(this, 0, true);
}

bool HeroLayer::ccTouchBegan(CCTouch *pTouch, CCEvent *pEvent)
{
	return true;
}

void HeroLayer::ccTouchMoved(CCTouch *pTouch, CCEvent *pEvent)
{
	moveHero(pTouch);
}

void HeroLayer::moveHero(CCTouch *pTouch)
{
	CCPoint currentPoint = pTouch->getLocationInView();
	currentPoint = CCDirector::sharedDirector()->convertToGL(currentPoint);
	CCPoint previousPoint = pTouch->getPreviousLocationInView();
	previousPoint = CCDirector::sharedDirector()->convertToGL(previousPoint);

	CCPoint distance = ccpSub(currentPoint, previousPoint);
	CCPoint destination = ccpAdd(hero->getPosition(), distance);

	hero->moveTo(destination);
}