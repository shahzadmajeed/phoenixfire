#include "EnemyBulletLayer.h"

USING_NS_CC;

EnemyBulletLayer::EnemyBulletLayer()
{
	bullets = CCArray::create();
	bullets->retain();
}

EnemyBulletLayer::~EnemyBulletLayer()
{
	bulletBatchNode->release();
	bullets->release();
	bullets = NULL;
}

EnemyBulletLayer* EnemyBulletLayer::create()
{
	EnemyBulletLayer *bulletLayer = new EnemyBulletLayer();
	if(bulletLayer && bulletLayer->init())
	{
		bulletLayer->autorelease();
		return bulletLayer;
	}
	CC_SAFE_DELETE(bulletLayer);
	return NULL;
}

bool EnemyBulletLayer::init()
{
	if(!CCLayer::init()) return false;

	bulletBatchNode = CCSpriteBatchNode::create("bullet.png");
	bulletBatchNode->retain();
	this->addChild(bulletBatchNode);
	this->scheduleUpdate();

	return true;
}

void EnemyBulletLayer::update(float delta)
{
	CCArray *allBullets = bulletBatchNode->getChildren();
	CCArray *bulletsToDelete = CCArray::create();
	CCObject *obj = NULL;
	float visibleHeight = CCDirector::sharedDirector()->getVisibleSize().height;

	CCARRAY_FOREACH(allBullets, obj)
	{
		Bullet *bullet = (Bullet *)obj;
		if(bullet->getPosition().y < 0)
		{
			bulletsToDelete->addObject(bullet);
		}
	}

	this->removeBullets(bulletsToDelete);
}

void EnemyBulletLayer::addBullet(CCPoint position)
{
	Bullet *bullet = Bullet::createWithTexture(bulletBatchNode->getTexture());
	bullet->setScale(0.3f);
	bullet->setPosition(position);
	bullet->fly(-0.5f * PI);

	bulletBatchNode->addChild(bullet);
}

CCArray* EnemyBulletLayer::getAllBullets()
{
	return bulletBatchNode->getChildren();
}

void EnemyBulletLayer::removeBullets(CCArray *bulletsToDelete)
{
	CCObject *obj = NULL;
	CCARRAY_FOREACH(bulletsToDelete, obj)
	{
		bulletBatchNode->removeChild((CCNode*)obj, true);
	}
}