#include "EnemyLayer.h"

USING_NS_CC;

EnemyLayer* EnemyLayer::create(EnemyBulletLayer *layer)
{
	EnemyLayer *enemyLayer = new EnemyLayer();
	if(enemyLayer && enemyLayer->init())
	{
		enemyLayer->setBulletLayer(layer);
		enemyLayer->addEnemy();
		enemyLayer->autorelease();
		return enemyLayer;
	}
	CC_SAFE_DELETE(enemyLayer);
	return NULL;
}

bool EnemyLayer::init()
{
	if(!CCLayer::init()) return false;
	scheduleUpdate();

	return true;
}

void EnemyLayer::addEnemy()
{
	Enemy *enemy = Enemy::create("enemy.png");
	enemy->setLife(700);
	enemy->setScale(0.7f);
	enemy->setBulletLayer(bulletLayer);
	enemy->move();
	this->addChild(enemy,0,0);
}

void EnemyLayer::update(float delta)
{
	Enemy *enemy = (Enemy *)getChildByTag(0);
	enemy->fire(delta);

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

void EnemyLayer::setBulletLayer(EnemyBulletLayer *layer)
{
	this->bulletLayer = layer;
}