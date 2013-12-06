#include "Enemy.h"

USING_NS_CC;

Enemy* Enemy::create(const char *pszFileName)
{
	Enemy *enemy = new Enemy();
	if(enemy && enemy->initWithFile(pszFileName))
	{
		enemy->addCannons();
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
		visibleSize.height - (boundingBox().getMaxY() - boundingBox().getMinY()) + 70
		)));
	actions->addObject(CCMoveTo::create(2.5f, ccp(300, 
		visibleSize.height - (boundingBox().getMaxY() - boundingBox().getMinY()) + 70
		)));
	actions->addObject(CCCallFunc::create(this, callfunc_selector(Enemy::foreverMove)));
	runAction(CCSequence::create(actions));
}

void Enemy::foreverMove()
{
	CCSize visibleSize = CCDirector::sharedDirector()->getVisibleSize();

	CCArray *foreverMove = CCArray::create();
	foreverMove->addObject(CCMoveTo::create(5.0f, ccp(visibleSize.width - 300, getPositionY())));
	foreverMove->addObject(CCMoveTo::create(5.0f, ccp(300, getPositionY())));

	runAction(CCRepeatForever::create(CCSequence::create(foreverMove)));
}

// return if hit
boolean Enemy::detectCollusion(Bullet *bullet)
{
	// I use a circle represent the enemy.
	CCRect area = boundingBox();
	// center point of the circle.
	CCPoint center = ccp(
		area.getMidX(),
		area.getMinY() + area.size.width / 2 + 13);
	float radius = area.size.width / 2 + 12;
	if(bullet->getPosition().getDistance(center) < radius)
	{
		this->life -= bullet->getDamage();
		return true;
	}
	return false;
}

void Enemy::setLife(float life)
{
	this->life = life;
}

float Enemy::getLife()
{
	return this->life;
}

void Enemy::addCannons()
{
	CCSize enemySize = boundingBox().size;

	Cannon *cannon = Cannon::create("cannon.png", 0.13f);
	cannon->setScale(0.5f);
	cannon->setPosition(ccp(enemySize.width / 2,30));
	addChild(cannon);
}

void Enemy::setBulletLayer(EnemyBulletLayer *layer)
{
	CCObject *obj = NULL;
	CCARRAY_FOREACH(this->getChildren(), obj)
	{
		Cannon *cannon = (Cannon *)obj;
		cannon->setBulletLayer(layer);
	}
}

void Enemy::fire(float deltaTime)
{
	CCObject *obj = NULL;
	CCARRAY_FOREACH(this->getChildren(), obj)
	{
		Cannon *cannon = (Cannon *)obj;
		cannon->fire(deltaTime);
	}
}