#include "Game.h"

#include "Bullet.h"

USING_NS_CC;

CCScene* Game::scene()
{
    CCScene *scene = CCScene::create();
    Game *layer = Game::create();
    scene->addChild(layer);

    return scene;
}

bool Game::init()
{
	if ( !CCLayerColor::initWithColor(ccc4(255, 255, 255, 255)) )
    {
        return false;
    }
    
    CCSize visibleSize = CCDirector::sharedDirector()->getVisibleSize();
    CCPoint origin = CCDirector::sharedDirector()->getVisibleOrigin();

    // init hero
    pHero = CCSprite::create("hero.png");
	pHero->setScale(0.13f);
    pHero->setPosition(ccp(visibleSize.width/2 + origin.x, visibleSize.height/10 + origin.y));
    this->addChild(pHero, 0);

	this->scheduleUpdate();
	this->setTouchEnabled(true);
    
    return true;
}

void Game::ccTouchesMoved(CCSet *pTouches, CCEvent *pEvent)
{
	CCTouch *pTouch = (CCTouch *)pTouches->anyObject();
	CCPoint currentPoint = pTouch->getLocationInView();
	currentPoint = CCDirector::sharedDirector()->convertToGL(currentPoint);
	CCPoint previousPoint = pTouch->getPreviousLocationInView();
	previousPoint = CCDirector::sharedDirector()->convertToGL(previousPoint);

	CCPoint distance = ccpSub(currentPoint, previousPoint);
	CCPoint destination = ccpAdd(pHero->getPosition(), distance);

	pHero->setPosition(destination);
}

float fireEneryBar = 0;
void Game::update(float delta)
{
	if((fireEneryBar += delta) > BULLET_INTERVAL)
	{
		fireEneryBar = 0;
		CCSprite *pBullet = CCSprite::create("bullet.png");
		pBullet->setPosition(pHero->getPosition());
		this->addChild(pBullet);
	}
	
}