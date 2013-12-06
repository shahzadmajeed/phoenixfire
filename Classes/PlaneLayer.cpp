#include "PlaneLayer.h"

USING_NS_CC;

Plane *PlaneLayer::Hero = NULL;

bool PlaneLayer::init()
{
	if (!CCLayer::init()) return false;

	// Init hero
	CCSize visibleSize = CCDirector::sharedDirector()->getVisibleSize();
    CCPoint origin = CCDirector::sharedDirector()->getVisibleOrigin();

	PlaneLayer::Hero = Plane::create("hero.png", 0.13f);
	PlaneLayer::Hero->setScale(0.13f);
    PlaneLayer::Hero->setPosition(ccp(visibleSize.width/2 + origin.x, visibleSize.height/10 + origin.y));
    this->addChild(Hero, 1);

	this->scheduleUpdate();
	this->setTouchEnabled(true);
    
    return true;
}

void PlaneLayer::ccTouchesMoved(CCSet *pTouches, CCEvent *pEvent)
{
	// Move hero
	CCTouch *pTouch = (CCTouch *)pTouches->anyObject();
	CCPoint currentPoint = pTouch->getLocationInView();
	currentPoint = CCDirector::sharedDirector()->convertToGL(currentPoint);
	CCPoint previousPoint = pTouch->getPreviousLocationInView();
	previousPoint = CCDirector::sharedDirector()->convertToGL(previousPoint);

	CCPoint distance = ccpSub(currentPoint, previousPoint);
	CCPoint destination = ccpAdd(Hero->getPosition(), distance);

	Hero->moveTo(destination);
}

void PlaneLayer::update(float delta)
{
	Hero->fire(delta);
}

void PlaneLayer::setBulletLayer(HeroBulletLayer *layer)
{
	Hero->setBulletLayer(layer);
}