#include "plane.h"

USING_NS_CC;

Plane* Plane::create(const char *pszFileName, float fireInterval)
{
	Plane *plane = new Plane();
	if(plane && plane->initWithFile(pszFileName))
	{
		plane->setFireInterval(fireInterval);
		plane->initFireEnergyBar();
		plane->autorelease();
		return plane;
	}
	CC_SAFE_DELETE(plane);
	return NULL;
}

void Plane::moveTo(CCPoint destination)
{
	runAction(CCEaseIn::create(CCMoveTo::create(0.5f, destination), 0.19f));
}

void Plane::fire(float deltaTime)
{
	if((fireEnergyBar += deltaTime) > fireInterval)
	{
		initFireEnergyBar();
		BulletLayer::sharedBulletLayer->addBullet(Bullet::OurBullet, ccpAdd(getPosition(), ccp(0, 20)));
	}
}

void Plane::setFireInterval(float fireInterval)
{
	this->fireInterval = fireInterval;
}

void Plane::initFireEnergyBar()
{
	fireEnergyBar = 0;
}