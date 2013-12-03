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
	// check Collosion
	CCArray *enemiesToDelete = CCArray::create();
	CCArray *bulletsToDelete = CCArray::create();

	CCArray *allEnemies = this->enemyLayer->getChildren();
	CCArray *allBullets = this->bulletLayer->getAllBullets();

	CCObject *enemyObj = NULL;
	CCObject *bulletObj = NULL;

	CCARRAY_FOREACH(allEnemies, enemyObj)
	{
		Enemy *enemy = (Enemy *)enemyObj;
		CCARRAY_FOREACH(allBullets, bulletObj)
		{
			Bullet *bullet = (Bullet *)bulletObj;
			if(enemy->boundingBox().intersectsRect(bullet->boundingBox()))
			{
				enemiesToDelete->addObject(enemyObj);
				bulletsToDelete->addObject(bulletObj);
			}
		}
	}

	bulletLayer->removeBullets(bulletsToDelete);
	enemyLayer->removeEnemies(enemiesToDelete);
}