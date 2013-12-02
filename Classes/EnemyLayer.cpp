#include "EnemyLayer.h"

USING_NS_CC;

bool EnemyLayer::init()
{
	if(!CCLayer::init()) return false;

	schedule(schedule_selector(EnemyLayer::addEnemy), 1);
	scheduleUpdate();

	return true;
}

void EnemyLayer::addEnemy(float delta)
{
	CCSize visibleSize = CCDirector::sharedDirector()->getVisibleSize();

	CCSprite *enemy = CCSprite::create("hero.png");
	enemy->setScaleX(0.13f);
	enemy->setScaleY(-0.13f);
	enemy->setPosition(ccp(rand()%(int)visibleSize.width, (int)visibleSize.height-20));
	enemy->runAction(CCMoveTo::create(4, ccp(enemy->getPositionX(), -20)));
	this->addChild(enemy);
}

void EnemyLayer::update(float delta)
{
	CCArray *allEnemies = this->getChildren();
	CCArray *EnemiesToDelete = CCArray::create();
	CCObject *obj = NULL;

	CCARRAY_FOREACH(allEnemies, obj)
	{
		CCSprite *enemy = (CCSprite *)obj;
		if(enemy->getPosition().y < -10)
		{
			EnemiesToDelete->addObject(enemy);
		}
	}

	CCARRAY_FOREACH(EnemiesToDelete, obj)
	{
		removeChild((CCNode*)obj);
	}
}