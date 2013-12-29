#include "GameLayer.h"

USING_NS_CC;

bool GameLayer::init()
{
	if (!CCLayer::init()) return false;

	// init Hero
	TestHero1 *mhero = TestHero1::create();
	mhero->setPosition(ccp(380,100));
	this->hero = mhero;
	addChild(this->hero);

	setTouchEnabled(true);
    
    return true;
}

// Let user move hero
void GameLayer::registerWithTouchDispatcher()
{
	CCDirector::sharedDirector()->getTouchDispatcher()->addTargetedDelegate(this, 0, true);
}

bool GameLayer::ccTouchBegan(CCTouch *pTouch, CCEvent *pEvent)
{
	return true;
}

void GameLayer::ccTouchMoved(CCTouch *pTouch, CCEvent *pEvent)
{
	moveHero(pTouch);
}

void GameLayer::moveHero(CCTouch *pTouch)
{
	CCPoint currentPoint = pTouch->getLocationInView();
	currentPoint = CCDirector::sharedDirector()->convertToGL(currentPoint);
	CCPoint previousPoint = pTouch->getPreviousLocationInView();
	previousPoint = CCDirector::sharedDirector()->convertToGL(previousPoint);

	CCPoint distance = ccpSub(currentPoint, previousPoint);
	CCPoint destination = ccpAdd(hero->getPosition(), distance);

	hero->setPosition(destination);
}