#include "EnemyLayer.h"

USING_NS_CC;

bool EnemyLayer::init()
{
	if(!CCLayer::init()) return false;

	addEnemy();
	scheduleUpdate();

	return true;
}

void EnemyLayer::addEnemy()
{
	Enemy *enemy = Enemy::create("enemy.png");
	enemy->setLife(2000);
	enemy->setScale(0.7f);
	enemy->move();
	this->addChild(enemy,0,0);
}

void EnemyLayer::update(float delta)
{
	Enemy *enemy = (Enemy *)getChildByTag(0);

	if(enemy->getLife() <= 0)
	{
		removeChild((CCNode*)enemy);
		addEnemy();
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