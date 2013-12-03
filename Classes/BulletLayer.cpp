#include "BulletLayer.h"

USING_NS_CC;

BulletLayer *BulletLayer::sharedBulletLayer = NULL;

BulletLayer::BulletLayer()
{
	bullets = CCArray::create();
	bullets->retain();
}

BulletLayer::~BulletLayer()
{
	bullets->release();
	bullets = NULL;
}

BulletLayer* BulletLayer::create()
{
	BulletLayer *bulletLayer = new BulletLayer();
	if(bulletLayer && bulletLayer->init())
	{
		BulletLayer::sharedBulletLayer = bulletLayer;
		bulletLayer->autorelease();
		return bulletLayer;
	}
	CC_SAFE_DELETE(bulletLayer);
	return NULL;
}

bool BulletLayer::init()
{
	if(!CCLayer::init()) return false;

	bulletBatchNode = CCSpriteBatchNode::create("bullet.png");
	this->addChild(bulletBatchNode);
	this->scheduleUpdate();

	return true;
}

void BulletLayer::update(float delta)
{
	CCArray *allBullets = bulletBatchNode->getChildren();
	CCArray *bulletsToDelete = CCArray::create();
	CCObject *obj = NULL;
	float visibleHeight = CCDirector::sharedDirector()->getVisibleSize().height;

	CCARRAY_FOREACH(allBullets, obj)
	{
		Bullet *bullet = (Bullet *)obj;
		if(bullet->getPosition().y > visibleHeight)
		{
			bulletsToDelete->addObject(bullet);
		}
	}

	this->removeBullets(bulletsToDelete);
}

void BulletLayer::addBullet(CCPoint position)
{
	Bullet *bullet = Bullet::createWithTexture(bulletBatchNode->getTexture());
	bullet->setScale(0.3f);
	bullet->setPosition(position);
	bullet->fly();

	bulletBatchNode->addChild(bullet);
}

CCArray* BulletLayer::getAllBullets()
{
	return bulletBatchNode->getChildren();
}

void BulletLayer::removeBullets(CCArray *bulletsToDelete)
{
	CCObject *obj = NULL;
	CCARRAY_FOREACH(bulletsToDelete, obj)
	{
		bulletBatchNode->removeChild((CCNode*)obj, true);
	}
}