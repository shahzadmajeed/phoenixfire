#include "GameScene.h"

USING_NS_CC;

bool GameScene::init()
{
	if(!CCScene::init()) return false;

	gameLayer = GameLayer::create();
	if(!gameLayer) return false;
	this->addChild(gameLayer);

	enemyBulletLayer = EnemyBulletLayer::create();
	if(!enemyBulletLayer) return false;
	this->addChild(enemyBulletLayer);

	enemyLayer = EnemyLayer::create(enemyBulletLayer);
	if(!enemyLayer) return false;
	this->addChild(enemyLayer);

	heroBulletLayer = HeroBulletLayer::create();
	if(!heroBulletLayer) return false;
	this->addChild(heroBulletLayer);

	planeLayer = PlaneLayer::create();
	if(!planeLayer) return false;
	planeLayer->setBulletLayer(heroBulletLayer);
	this->addChild(planeLayer);

	this->scheduleUpdate();

	return true;
}

void GameScene::update(float delta)
{
	CCArray *bulletsToDelete = CCArray::create();

	Enemy *enemy = (Enemy *)this->enemyLayer->getChildByTag(0);
	CCArray *allBullets = this->heroBulletLayer->getAllBullets();

	CCObject *bulletObj = NULL;

	CCARRAY_FOREACH(allBullets, bulletObj)
	{
		Bullet *bullet = (Bullet *)bulletObj;
		if(enemy->boundingBox().intersectsRect(bullet->boundingBox()))
		{
			if(enemy->detectCollusion(bullet))
			{
				CCLOG("enemy life: %f", enemy->getLife());
				bulletsToDelete->addObject(bullet);
			}
		}
	}

	heroBulletLayer->removeBullets(bulletsToDelete);
	bulletsToDelete->removeAllObjects();

	Plane *hero = (Plane *)this->planeLayer->Hero;
	allBullets = this->enemyBulletLayer->getAllBullets();

	CCARRAY_FOREACH(allBullets, bulletObj)
	{
		Bullet *bullet = (Bullet *)bulletObj;
		if(hero->boundingBox().intersectsRect(bullet->boundingBox()))
		{
			if(hero->detectCollusion(bullet))
			{
				CCLOG("our life: %f", hero->getLife());
				bulletsToDelete->addObject(bullet);
			}
		}
	}

	enemyBulletLayer->removeBullets(bulletsToDelete);
}