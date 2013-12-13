#include "HeroBulletLayer.h"

USING_NS_CC;

HeroBulletLayer::HeroBulletLayer()
{
	bullets = CCArray::create();
	bullets->retain();
}

HeroBulletLayer::~HeroBulletLayer()
{
	bullets->release();
	bullets = NULL;
}

HeroBulletLayer* HeroBulletLayer::create()
{
	HeroBulletLayer *bulletLayer = new HeroBulletLayer();
	if(bulletLayer && bulletLayer->init())
	{
		bulletLayer->autorelease();
		return bulletLayer;
	}
	CC_SAFE_DELETE(bulletLayer);
	return NULL;
}

bool HeroBulletLayer::init()
{
	if(!CCLayer::init()) return false;

	bulletBatchNode = CCSpriteBatchNode::create("bullet.png");
	this->addChild(bulletBatchNode);
	this->scheduleUpdate();

	return true;
}

void HeroBulletLayer::update(float delta)
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

void HeroBulletLayer::addBullet(CCPoint position)
{
	Bullet *bullet = Bullet::createWithTexture(bulletBatchNode->getTexture());
	bullet->setScale(0.3f);
	bullet->setPosition(position);
	bullet->fly(0.5f * PI);

	bulletBatchNode->addChild(bullet);
}

CCArray* HeroBulletLayer::getAllBullets()
{
	return bulletBatchNode->getChildren();
}

void HeroBulletLayer::removeBullets(CCArray *bulletsToDelete)
{
	CCObject *obj = NULL;
	CCARRAY_FOREACH(bulletsToDelete, obj)
	{
		bulletBatchNode->removeChild((CCNode*)obj, true);
	}
}