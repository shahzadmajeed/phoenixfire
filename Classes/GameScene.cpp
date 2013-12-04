#include "GameScene.h"

USING_NS_CC;

bool GameScene::init()
{
	if(!CCScene::init()) return false;

	gameLayer = GameLayer::create();
	if(!gameLayer) return false;
	this->addChild(gameLayer);

	enemyLayer = EnemyLayer::create();
	if(!enemyLayer) return false;
	this->addChild(enemyLayer);

	planeLayer = PlaneLayer::create();
	if(!planeLayer) return false;
	this->addChild(planeLayer);

	bulletLayer = BulletLayer::create();
	if(!bulletLayer) return false;
	this->addChild(bulletLayer);

	this->scheduleUpdate();

	return true;
}

void GameScene::update(float delta)
{
	CCArray *bulletsToDelete = CCArray::create();

	Enemy *enemy = (Enemy *)this->enemyLayer->getChildByTag(0);
	CCArray *allBullets = this->bulletLayer->getAllBullets();

	CCObject *bulletObj = NULL;

	CCARRAY_FOREACH(allBullets, bulletObj)
	{
		Bullet *bullet = (Bullet *)bulletObj;
		if(enemy->boundingBox().intersectsRect(bullet->boundingBox()))
		{
			enemy->hitedByBullet(bullet);
			CCLOG("enemy life: %f", enemy->getLife());
			bulletsToDelete->addObject(bullet);
		}
	}

	bulletLayer->removeBullets(bulletsToDelete);
}