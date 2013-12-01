#include "BulletLayer.h"

USING_NS_CC;

BulletLayer *BulletLayer::sharedBulletLayer = NULL;

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

	return true;
}

void BulletLayer::addBullet(Bullet::BulletType type, CCPoint position)
{
	switch (type)
	{
	case Bullet::BulletType::OurBullet:
		Bullet *bullet = Bullet::createWithTexture(bulletBatchNode->getTexture());
		bullet->setScale(0.3f);
		bullet->setPosition(position);
		bullet->fly();
		this->addChild(bullet);
		break;
	}
}