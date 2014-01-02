#include "GameLayer.h"

#include "Units/PlaneFactory.h"
#include "Game.h"
#include "Units/Enginefire.h"
#include "particle_nodes/CCParticleSystemQuad.h"

USING_NS_CC;

GameLayer::GameLayer()
{
	gameBatch = NULL;
	enemies = NULL;
}

bool GameLayer::init()
{
	if (!CCLayer::init()) return false;

	gameBatch = CCSpriteBatchNode::create("gameTexture.png");
	this->addChild(gameBatch);

	enemies = CCArray::create();

	initHero();
	createEnemy();

	setTouchEnabled(true);
    
    return true;
}

void GameLayer::initHero()
{
	PlaneFactory factory;

	// if hero existed, free it first.
	if(Game::sharedGame->getHero())
	{
		Game::sharedGame->getHero()->removeFromParent();
	}		

	Plane *mhero = factory.createPlane(PlaneFactory::PlaneType::HERO1);
	Enginefire *fire = Enginefire::create(mhero, 0, 0.6f, ccp(0, -100));

	Game::sharedGame->setHero(mhero);
	mhero->setPosition(ccp(380,100));
	this->addChild(mhero);
	this->addChild(fire);
}

void GameLayer::createEnemy()
{
	PlaneFactory factory;

	Plane *mEnemy = factory.createPlane(PlaneFactory::PlaneType::ENEMY1);
	mEnemy->setPosition(ccp(390, 1400));
	enemies->addObject(mEnemy);
	this->addChild(mEnemy);
}

void GameLayer::addBullet(Bullet *bullet)
{
	gameBatch->addChild(bullet);
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
	CCPoint destination = ccpAdd(Game::sharedGame->getHero()->getPosition(), distance);

	if(destination.x < 0) destination.x = 0;
	else if(destination.x > 760) destination.x = 760;

	if(destination.y < 0) destination.y = 0;
	else if(destination.y > 1280) destination.y = 1280;

	Game::sharedGame->getHero()->setPosition(destination);
}