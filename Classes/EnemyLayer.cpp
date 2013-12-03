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
	Enemy *enemy = Enemy::create("hero.png");
	enemy->setScaleX(0.13f);
	enemy->setScaleY(-0.13f);
	enemy->move();
	this->addChild(enemy);
}

void EnemyLayer::update(float delta)
{
	CCArray *allEnemies = this->getChildren();
	CCArray *EnemiesToDelete = CCArray::create();
	CCObject *obj = NULL;

	CCARRAY_FOREACH(allEnemies, obj)
	{
		Enemy *enemy = (Enemy *)obj;
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

void EnemyLayer::removeEnemies(CCArray *enemiesToDelete)
{
	CCObject *obj = NULL;
	CCARRAY_FOREACH(enemiesToDelete, obj)
	{
		removeChild((CCNode*)obj);
	}
}