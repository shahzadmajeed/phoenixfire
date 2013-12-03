#include "Enemy.h"

USING_NS_CC;

Enemy* Enemy::create(const char *pszFileName)
{
	Enemy *enemy = new Enemy();
	if(enemy && enemy->initWithFile(pszFileName))
	{
		enemy->autorelease();
		return enemy;
	}
	CC_SAFE_DELETE(enemy);
	return NULL;
}

void Enemy::move()
{
	CCSize visibleSize = CCDirector::sharedDirector()->getVisibleSize();

	CCArray *actions = CCArray::create();

	this->setPosition(ccp(visibleSize.width/2, visibleSize.height + (boundingBox().getMaxY() - boundingBox().getMinY()) / 2));

	// enemy getting in...
	actions->addObject(CCMoveTo::create(3, ccp(getPositionX(), 
		visibleSize.height - (boundingBox().getMaxY() - boundingBox().getMinY())
		)));
	actions->addObject(CCMoveTo::create(2.5f, ccp(0, 
		visibleSize.height - (boundingBox().getMaxY() - boundingBox().getMinY())
		)));
	actions->addObject(CCCallFunc::create(this, callfunc_selector(Enemy::foreverMove)));
	runAction(CCSequence::create(actions));
}

void Enemy::foreverMove()
{
	CCSize visibleSize = CCDirector::sharedDirector()->getVisibleSize();

	CCArray *foreverMove = CCArray::create();
	foreverMove->addObject(CCMoveTo::create(5.0f, ccp(visibleSize.width, getPositionY())));
	foreverMove->addObject(CCMoveTo::create(5.0f, ccp(0, getPositionY())));

	runAction(CCRepeatForever::create(CCSequence::create(foreverMove)));
}